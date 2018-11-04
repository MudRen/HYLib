// npc.c

#include <command.h>

inherit CHARACTER;
inherit F_CLEAN_UP;

object carry_object(string file)
{
	object ob;

	if( !objectp(ob = new(file)) ) return 0;
	ob->move(this_object());
	return ob;
}

object add_money(string type, int amount)
{
	object ob;

	if (!clonep()) return 0;
	ob = carry_object("/clone/money/" + type);
	if( !ob ) return 0;
	ob->set_amount(amount);
}

int accept_fight(object who)
{
	string att;

	att = query("attitude");

	if( is_fighting() )	switch(att) {
		case "heroism":
			command("say �ߣ����аɣ�\n");
			break;
		default:
			command("say ���ж�Ϊʤ���ⲻ������̫����\n");
			return 0;
	}

	if( (int)query("jing") * 100 / (int)query("max_jing") >= 90
	&&	(int)query("qi") * 100 / (int)query("max_qi") >= 90 ) {
		switch(att) {
			case "friendly":
				command("say " + RANK_D->query_self(this_object())
					+ "��ô������" + RANK_D->query_respect(who)
					+ "�Ķ��֣�\n");
				return 0;
			case "aggressive":
			case "killer":
				command("say �ߣ����аɣ�\n");
				break;
			default:
				if( !is_fighting() )
					command("say ��Ȼ" + RANK_D->query_respect(who)
						+ "�ͽ̣�" + RANK_D->query_self(this_object())
						+ "ֻ�÷��㡣\n");
		}
		return 1;
	} else
		return 0;
}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int intellgent_behavor()
{
	int enc,max;
	object *inv;
	enc = (int) query_encumbrance();
	max =  (int) query_max_encumbrance();
	if(enc * 3 < max)
	command("get all");
	return 1;
}

int return_home(object home)
{
	// Are we at home already?
	if( !environment()
	||	environment()==home )
		return 1;

	// Are we able to leave?
        this_object()->set_leader(0);
	if( !living(this_object())
	||	is_fighting())return 0;
//	||	!mapp(environment()->query("exits")) ) return 0;

	// Leave for home now.
	message("vision", this_object()->name() + "����ææ���뿪�ˡ�\n",
		environment(), this_object());
        if (move(home)) {
                message("vision", this_object()->name() + "����ææ�����˹�����\n",
                        environment(), this_object());
                return 1;
        }
        return 0;
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
	string *msg,*emotes;
	int chance, rnd;
        object *inv;
        string action,target;

	if( !environment() ) return 0;
//	if(query("intellgent")) intellgent_behavor();
        if( query_temp("is_unconcious") ) return 0;

        if (query("neili")>100 && query("max_neili") > 200 
            && query("race") == "����" && !is_busy()) {
                if (query("eff_jing")
                && query("jing")*100/query("eff_jing") <= 80)
                        command("exert regenerate");

                if (query("eff_qi") && query("qi") >= 0
                && query("qi")*100/query("eff_qi") <= 80)
                        command("exert recover");
                              
                if (query("eff_qi") && query("qi") >= 0
                && query("max_qi") && !is_fighting() && !query("mute")
                && query_skill_mapped("force")
                && query_skill("force") > 50
                && query("eff_qi") < query("max_qi")
                && query("eff_qi") >= query("max_qi")/3)
                        command("exert heal");

                if (query("max_neili")
                && query("neili")*100/query("max_neili") <= 80
                && !is_fighting()
                && query_skill("force") > 50
                && query_skill_mapped("force")
                && query("combat_exp")>500000)
                command("dazuo 20");

        }
        if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
		return 0;

 /*       if(!random(250) && !is_fighting() && !is_ghost() ){

            emotes = EMOTE_D->query_all_emote();

            inv = all_inventory(environment());

            action = emotes[random(sizeof(emotes))];

            target = inv[random(sizeof(inv))]->query("id");

           (!random(3) )? command(action) : command(action +" "+target);

        }
        if( !query_temp("no_kill") ) 
        {
        if(!random(1500) && !is_fighting() && !is_ghost() ){

            inv = all_inventory(environment());

            target = inv[random(sizeof(inv))]->query("id");

            command("fight"+" "+target);

        }

        if(!random(3000) && !is_fighting() && !is_ghost() ){

            inv = all_inventory(environment());

            target = inv[random(sizeof(inv))]->query("id");

            if (  target->query("age")>17 ){
            if (!query("shen")>0 && target->query("shen")<1000 ){
            command("say �������ְ��࣬���˵ö���֮��");
            command("kill"+" "+target);
            }
            if (!query("shen")<0 && target->query("shen")>1000 ){
            command("say �����˳�ۣ�������Щ���������ˣ�");
            command("kill"+" "+target);
            }
            }
            command("say ��Ҫ����!");
        }
        }
*/
  if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
        if( query_temp("is_unconcious") ) return 0;
		if( random(100) < chance ) {
			rnd = random(sizeof(msg));
			if( stringp(msg[rnd]) )
				say(msg[rnd]);
			else if( functionp(msg[rnd]) )
				return evaluate(msg[rnd]);
		}
		return 1;
	}
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
        mapping exits;
        string *dirs;
        object me = this_object();

//        if (!query_heart_beat(me)) return 0;
	if( !environment(me) ) return 0;
        if( me->query_temp("is_unconcious") ) return 0;

	if( !living(me)) return 0;

	if( !mapp(exits = environment()->query("exits")) ) return 0;
        if( !environment() 
        || !mapp(exits = environment()->query("exits")) 
        || me->is_busy())
// || me->is_fighting()
        return 0;                 
//        if( !mapp(exits = environment()->query("exits")) 
//        || me->is_busy()) return 0;
        dirs = keys(exits);
        if (!dirs)  return 0;
        if (sizeof(dirs) < 1) return 0;
        command("go " + dirs[random(sizeof(dirs))]);
}


// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
	string spell_skill;

	if( stringp(spell_skill = query_skill_mapped("spells")))
		SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}

// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
	string force_skill;

	if( stringp(force_skill = query_skill_mapped("force")))
		SKILL_D(force_skill)->exert_function(this_object(), func);
}

// Default chat function: Let the npc perform special action with 
// his/her enabled martial art
int perform_action(string action)
{
	object weapon;
	string martial_skill, act;

        if( query_temp("is_unconcious") ) return 0;
	if( sscanf(action, "%s.%s", martial_skill, act) != 2 )
		return 0;
	martial_skill = query_skill_mapped(martial_skill);
	if( stringp(martial_skill) )
		return SKILL_D(martial_skill)->perform_action(this_object(), act);		
}

// Following add for making love...hehe ! Dec.1997 Venus
int accept_ai(object who)
{
	int tage;

	tage = query("age");

	if (tage>17)
	{
		command("say ����" + RANK_D->query_respect(who)
	+ "���ۣ�" + RANK_D->query_self(this_object())	+ "�������������\n");
		return 1;
	} else
		return 0;
}

