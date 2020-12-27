#pragma once

#include <common/constants.hpp>
#include <common/ring.hpp>

#include <array>
#include <cmath>
#include <sstream>
#include <string>
#include <variant>

namespace server {
  enum class error_state{
  player_out_of_bounds,
  server_idle
  };

struct round_state {
	round_state()=default;
	round_state(const round_state &)=default;
	round_state(round_state &&)=default;
	round_state& operator=(const round_state &)=default;
    enum  class player_state{
        fold,
        not_played
    };
    friend std::ostream & operator<<(std::ostream & stream,player_state p){
      if (p==player_state::fold)
        stream<<"-1";
      else stream<<"-2";
      return stream;
    }
    friend bool operator!=(const round_state& s1, const round_state& s2){
      	if(s1.array_if_has_played_ammount!=s2.array_if_has_played_ammount)
			return true;
		if (s1.live_max_bet!=s2.live_max_bet)
			return true;
		if (s1.money_pp != s2.money_pp)
			return true;
		return false;
    }
    using var_type=std::variant<player_state,unsigned>;
    using state_of_table=std::array<var_type,number_of_players>;
    //using state_of_table=ring<var_type,number_of_players> ;
    state_of_table array_if_has_played_ammount{var_type{300u},
                                    var_type{player_state::fold},
                                    var_type{200u},
                                    var_type{player_state::not_played}};
    ring<state_of_table> ring_if_has_played_ammount{array_if_has_played_ammount};
    //state_of_table.get_active_player() dinei ton active player
    unsigned live_max_bet{};
    std::array<unsigned,number_of_players> money_pp{};
    friend std::ostream& operator<<(std::ostream &stream, round_state d){
      stream<<d.live_max_bet<<"\n";
      for(auto i: d.array_if_has_played_ammount){
        std::visit([&stream](auto x ){
            stream<<x<<";";
        }, i);
      }
      stream<<"\n";
      for(auto i:d.money_pp){
        stream<<i<<";";
      }
      return stream;
    }
    friend std::istream& operator>>(std::istream &stream, round_state d){
      std::string s ;
      std::getline(stream,s);
      d.live_max_bet=stoi(s);
      std::getline(stream,s);
      std::string delimiter = ";";
      size_t pos = 0;
      unsigned count=0;
      while ((pos = s.find(delimiter)) != std::string::npos) {
          std::stringstream token(s.substr(0, pos));
          int x{};
          token>>x;
          if(x==-1)
            d.array_if_has_played_ammount.at(count)=player_state::fold;
          else if(x==-2)
            d.array_if_has_played_ammount.at(count)=player_state::not_played;
          else d.array_if_has_played_ammount.at(count)=static_cast<unsigned>(x);    
          count++;
          s.erase(0, pos + delimiter.length());
      }
      std::getline(stream,s);
      count=0;
      while ((pos = s.find(delimiter)) != std::string::npos) {
          std::stringstream token(s.substr(0, pos));
          unsigned x{};
          d.money_pp.at(count)=x;
          count++;
          s.erase(0, pos + delimiter.length());
      }
      return stream;
    }
};

} // namespace server
