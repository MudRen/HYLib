// damage.c
// 98-9-11 netplay@CCTX
//fix by tlt at 1999/6/29
#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

int ghost = 0;

int is_ghost() { return ghost; }

varargs int receive_damage(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: �˺��������( ֻ���� jing, qi ����֮һ )��\n");

	if( objectp(who) ) set_temp("last_damage_from", who);
	val = (int)query(type) - damage;

	if( val >= 0 ) set(type, val);
	else set( type, -1 );

	set_heart_beat(1);

	return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: �˺��������( ֻ���� jing, qi ����֮һ )��\n");

	if( objectp(who) ) set_temp("last_damage_from", who);
	val = (int)query("eff_" + type) - damage;

	if( val >= 0 ) set("eff_" + type, val);
	else {
		set( "eff_" + type, -1 );
		val = -1;
	}

	if( (int)query(type) > val ) set(type, val);

	set_heart_beat(1);

	return damage;
}

int receive_heal(string type, int heal)
{
	int val;

	if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: �ָ��������( ֻ���� jing, qi ����֮һ )��\n");

	val = (int)query(type) + heal;

	if( val > (int)query("eff_" + type) ) set(type, (int)query("eff_" + type));
	else set( type, val );

	return heal;
}

int receive_curing(string type, int heal)
{
	int max, val;

	if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: �ָ��������( ֻ���� jing, qi ����֮һ )��\n");

	val = (int)query("eff_" + type);
	max = (int)query("max_" + type);

	if( val + heal > max ) {
		set("eff_" + type, max);
		return max - val;
	} else {
		set( "eff_" + type, val + heal);
		return heal;
	}
}

void unconcious()
{
	object defeater,killer;
        object me;
        object riding;

        me = this_object();

	if( !living(this_object()) ) return;
	if( wizardp(this_object()) && query("env/immortal") ) return;
	
	//���ⷿ��Ķ��ε� idea
	if (environment() && environment()->query("alternative_unc")) {
		environment()->alternative_unc(this_object());
		return;
	}
	
        if (userp(this_object())&& environment(this_object())->query("bwdhpk"))
        {
                message_vision(HIR "����֮�أ�ֻ��ʤ��������������$N������˵�ȴ͵��һ����\n" NOR, this_object());
                message_vision(HIR "$N��̧����ȥ��\n" NOR, this_object());
	if( objectp(killer = query_temp("last_damage_from")) )
{
	killer->add_temp("bwdhpk",1);
message("channel:chat", HIC"������ս����"HIR + " "+this_object()->query("name")+"��"+killer->query("name")+"��������˴�ᣡ\n"NOR,users() );
}
	  this_object()->set("eff_jing", (int)this_object()->query("max_jing"));
	  this_object()->set("jing", (int)this_object()->query("max_jing"));
	  this_object()->set("eff_qi", (int)this_object()->query("max_qi"));
	  this_object()->set("qi", (int)this_object()->query("max_qi"));
	  this_object()->set("jingli", (int)this_object()->query("max_jingli"));
	  this_object()->set("neili", (int)this_object()->query("max_neili"));
	  this_object()->set("food", (int)this_object()->max_food_capacity());
	  this_object()->set("water", (int)this_object()->max_water_capacity());
	  this_object()->remove_all_killer();
	  this_object()->clear_condition();
          this_object()->move("/d/pk/pk/ready");
          return;
}

	//ƽ���ǲ���
//        if (environment(this_object())->query("pingan"))
//        {
//		message_vision(HIW "$N�ۿ���Ҫ�赹������ƽ���ǵ�ʥ��֮��ʹ$Nһ���Ӿ������˹�����\n" NOR, this_object());
//		this_object()->set("eff_jing",this_object()->query("max_jing"));
//		this_object()->set("jing",1);
//		this_object()->set("eff_qi",this_object()->query("max_qi"));
//		this_object()->set("qi",1);
//		return;
//	}

	if( objectp(defeater = query_temp("last_damage_from")) )
		COMBAT_D->winner_reward(defeater, this_object());

	if( objectp(defeater = query_temp("last_damage_from")) )
{
	set_temp("hunby",defeater->query("id"));
}
//        if (objectp(riding = me->query_temp("is_riding")))
//        {
//                message_vision("$Nһͷ��$n��������������\n",
//                              me, riding);
//                me->delete_temp("is_riding");
//                riding->delete_temp("is_rided_by");
//                riding->move(environment(me));
//        }
	this_object()->remove_all_enemy();
	set("hunmi",1);
        this_object()->delete_temp("fight/dodge");
	message("system", HIR "\n�����ǰһ�ڣ�����ʲôҲ��֪����....\n\n" NOR,
		this_object());
	this_object()->disable_player("<���Բ��ѣ����²�֪��>");
        this_object()->delete_temp("fight/dodge");

	set("jing", 0);
	set("qi", 0);
	set_temp("block_msg/all", 1);
	COMBAT_D->announce(this_object(), "unconcious");

	call_out("revive", random(100 - query("con")) + 30);
}

void revive(int quiet)
{
        int i;
	object me;
	object env;
	me = this_object();
	remove_call_out("revive");
	env = environment();
	if (env)
	{
		while (env->is_character() && environment(env))
			env = environment(env);
		if (env != environment())
                	this_object()->move(env);
	}

        delete("disable_type");
        set_temp("block_msg/all", 0);
        this_object()->enable_player();

	// write the prompt
	me->write_prompt();
	if( !quiet ) {
		COMBAT_D->announce(this_object(), "revive");
		set_temp("block_msg/all", 0);
		set("hunmi",0);
		
		message("system", HIY "\n������������������֪��....\n\n" NOR,
			this_object());
	} else
		{set_temp("block_msg/all", 0);set("hunmi",0);}
}


void die()
{
	object corpse, killer;
	int i;

	if( !living(this_object()) ) revive(1);
	if( wizardp(this_object()) && query("env/immortal") ) return;
	
	//���ⷿ��Ķ����� idea
	if (environment() && environment()->query("alternative_die")) {
		environment()->alternative_die(this_object());
		return;
	}
	//��̨���䲻��
	if ( userp(this_object()) && file_name(environment(this_object())) == "/d/city/leitai")
	{
		message_vision(HIR "��ƽ�ӵ������ѷ�ʤ����������������\n" NOR, this_object());
		this_object()->set("eff_jing",this_object()->query("max_jing"));
		this_object()->set("jing",this_object()->query("max_jing"));
		this_object()->set("eff_qi",this_object()->query("max_qi"));
		this_object()->set("qi",this_object()->query("max_qi"));
		return;
	}
	//ƽ���ǲ���
//    if((int)obj->query("age") <= 17 && userp(obj) && !obj->query_condition("killer"))
//        return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");

        if (userp(this_object())&& environment(this_object())->query("pingan") && (int)this_object()->query("age") <= 17)
        {
		message_vision(HIR "$N���������ˣ���$NͻȻ�����һ����ƽ��֮�ǣ���Զ�����������ֻ��˻��ˡ�\n" NOR, this_object());
		this_object()->set("eff_jing",100);
		this_object()->set("jing",1);
		this_object()->set("eff_qi",100);
		this_object()->set("qi",1);
		return;
	}

        //����������
        if (userp(this_object())&&environment(this_object())->query("biwu"))
        {
                message_vision(HIR "����֮�أ�ֻ��ʤ��������������$N������˵�ȴ͵��һ����\n" NOR, this_object());
                this_object()->set("eff_jing",this_object()->query("max_jing")/2);
                this_object()->set("jing",1);
                this_object()->set("eff_qi",this_object()->query("max_qi")/2);
                this_object()->set("qi",1);
                return;
        }

        if(userp(this_object())&& this_object()->is_ghost())
{
                message_vision(HIC "����û�а취����һ�Ρ�\n" NOR, this_object());
                message_vision(HIG "$N�Ļ��ǻص������䡣\n" NOR, this_object());
		this_object()->set("jing", 10);
		this_object()->set("eff_jing", 10);
		this_object()->set("qi", 10);
		this_object()->set("eff_qi", 10);
		this_object()->move(DEATH_ROOM);
}

        if (userp(this_object())&& environment(this_object())->query("bwdhpk"))
        {
                message_vision(HIR "����֮�أ�ֻ��ʤ��������������$N������˵�ȴ͵��һ����\n" NOR, this_object());
                message_vision(HIR "$N��̧����ȥ��\n" NOR, this_object());
	if( objectp(killer = query_temp("last_damage_from")) )
{
	killer->add_temp("bwdhpk",1);
message("channel:chat", HIC"������ս����"HIR + " "+this_object()->query("name")+"��"+killer->query("name")+"��������˴�ᣡ\n"NOR,users() );
}
	  this_object()->set("eff_jing", (int)this_object()->query("max_jing"));
	  this_object()->set("jing", (int)this_object()->query("max_jing"));
	  this_object()->set("eff_qi", (int)this_object()->query("max_qi"));
	  this_object()->set("qi", (int)this_object()->query("max_qi"));
	  this_object()->set("jingli", (int)this_object()->query("max_jingli"));
	  this_object()->set("neili", (int)this_object()->query("max_neili"));
	  this_object()->set("food", (int)this_object()->max_food_capacity());
	  this_object()->set("water", (int)this_object()->max_water_capacity());
	  this_object()->remove_all_killer();
	  this_object()->clear_condition();
          this_object()->move("/d/pk/pk/ready");
          return;
}

        if (userp(this_object())&& environment(this_object())->query("citybiwu"))
        {
                message_vision(HIR "����֮�أ�ֻ��ʤ��������������$N������˵�ȴ͵��һ����\n" NOR, this_object());
                message_vision(HIR "$N��̧����ȥ��\n" NOR, this_object());
		this_object()->set("jing", 50);	
		this_object()->set("eff_jing", 50);
		this_object()->set("qi", 50);
		this_object()->set("eff_qi", 50);
                this_object()->remove_all_killer();
                this_object()->unconcious();
                this_object()->move("d/city/wudao4");
                return;
        }
	// Clear all the conditions by death.
this_object()->remove_all_killer();
if (!this_object()->query_condition("killer"))
{
	this_object()->clear_condition();
}
    //call clear not here , in combatd.c 
        this_object()->set("killbyname","������");
	COMBAT_D->announce(this_object(), "dead");
	if( objectp(killer = query_temp("last_damage_from")) &&
		file_name(environment(killer)) == file_name(environment(this_object())))
	{
		this_object()->add("normal_die", 1);
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, this_object());
	}
	else

	message("channel:rumor", HIM"��ҥ�ԡ�"+"��˵"+this_object()->name()+
    "���� ��������\n"NOR, users());
	this_object()->add("dietimes",1);
        if (!environment(this_object())->query("no_death_penalty"))
        {
		if (this_object()->query("combat_exp")>500000
		||this_object()->query_condition("killer"))
{
	this_object()->add("combat_exp", -(int)this_object()->query("combat_exp") / 200);
}
        }
		
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	{
		corpse->move(environment());
// �����õľ���ֵ
		corpse->set("combat_exp", this_object()->query("combat_exp"));
// ���������
		if (userp(this_player()))
			corpse->set("userp", 1);
	}

	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());

	this_object()->dismiss_team();
	if( userp(this_object()) ) {
		if (this_object()->is_busy())
			this_object()->interrupt_me();
		set("jing", 1);	set("eff_jing", 1);
		set("qi", 1);	set("eff_qi", 1);
		ghost = 1;
		this_object()->move(DEATH_ROOM);
		DEATH_ROOM->start_death(this_object());
	} else
		destruct(this_object());
}

void reincarnate()
{
	ghost = 0;
	set("eff_jing", query("max_jing"));
	set("eff_qi", query("max_qi"));
}

int max_food_capacity() { return query_weight() / 200; }

int max_water_capacity() { return query_weight() / 200; }

int heal_up()
{
	int update_flag, i;
	mapping my;
	object ob=this_object();
     
	//	object where = environment(me);

//	if( this_object()->is_fighting() ) return -1;

	update_flag = 0;

	my = query_entire_dbase();

	if( my["water"] > 0 ) 
	{
	 my["water"] -= 1;update_flag++; 
	}
	if( my["food"] > 0 ) 
	{
	my["food"] -= 1;
	if ( my["food"] == ob->max_food_capacity()*0.3 )
		tell_object(ob,HIY "\n����ӹ���ֱ�У������óԵ㶫���ˡ�\n"NOR);
	if ( my["food"] == ob->max_food_capacity()*0.1 )
		{
		tell_object(ob,HIY "\n�����ֱ���ţ��Ͽ�Ե㶫���ɡ�\n"NOR);
		ob->delete_temp("foods");
		}
	update_flag++; 
	}
/*	else
	{	if (!ob->query_temp("foods"))
		{tell_object(ob,HIR "\n�����ֱð���ǣ�ʵ���Ƕ���ס�ˡ�\n"NOR);
		ob->set_temp("foods",10);}
	
		if ((int)ob->query_temp("foods") > 1) ob->add_temp("foods",-1);
		else {tell_object(ob,HIR "\n����ÿ�Ҫ���ˡ�������\n"NOR);  
                        if (userp(this_object())&& environment(this_object())->query("pingan") && (int)this_object()->query("age") <= 17)
		        {tell_object(ob,HIY "���������ƽ���ǣ���Զ�����ж������ˣ�ƽ��֮���յ��㾫������\n"NOR);
			ob->set("food",ob->max_food_capacity());ob->set("water",ob->max_water_capacity());
			}else
			if (wizardp(ob))
			{tell_object(ob,HIY "�����������ɣ�ֻ��������һ�У������һ��ѺóԵ�\n"+
					"�ۣ����к�����Ү�����㻩�����¾ͳԹ��ˣ����������Ƕ����ˣ�\n"NOR);
			ob->set("food",ob->max_food_capacity());ob->set("water",ob->max_water_capacity());
			}else
			if ((int)ob->query("age")<15) 
			{
			tell_object(ob,HIY "������û�������ڡ��������ͳ�һ֧��ƿ�ݺݵ��������ڣ����úù����ˡ�\n"NOR);
			ob->set("food",ob->max_food_capacity());ob->set("water",ob->max_water_capacity());
			}else
			{if (userp(ob))
			ob->unconcious();
			ob->set_temp("foods",10);
			}
		}
		update_flag++; 
	}
*/
	if( my["water"] < 1 && userp(this_object()) ) return update_flag;
    
	i = my["con"] / 3 + my["max_jingli"] / 10;
	if (ob->is_fighting()) i /= 3;
	my["jing"] += i;
	if( my["jing"] >= my["eff_jing"] ) {
		my["jing"] = my["eff_jing"];
		if( my["eff_jing"] < my["max_jing"] ) { my["eff_jing"] ++; update_flag++; }
	} else update_flag++;

	i = my["con"] / 3 + my["max_neili"] / 10;
	if (ob->is_fighting()) i /= 3;
	my["qi"] += i;
	if( my["qi"] >= my["eff_qi"] ) {
		my["qi"] = my["eff_qi"];
		if( my["eff_qi"] < my["max_qi"] ) { my["eff_qi"] ++; update_flag++; }
	} else update_flag++;

	if( my["food"] < 1 && userp(this_object()) ) return update_flag;

	if( my["max_jingli"] && my["jingli"] < my["max_jingli"] ) {
		my["jingli"] += (int)this_object()->query_skill("magic", 1) / 2;
		if( my["jingli"] > my["max_jingli"] ) my["jingli"] = my["max_jingli"];
		update_flag++;
	}

	if( my["max_neili"] && my["neili"] < my["max_neili"] ) {
	    i = (int)this_object()->query_skill("force", 1) / 2;
		if (ob->is_fighting()) i /= 3;
		my["neili"] += i;
		if( my["neili"] > my["max_neili"] ) my["neili"] = my["max_neili"];
		update_flag++;
	}
	if (ob->query("szj/passed") && ob->query("szj/over200") && my["max_neili"] && my["neili"] < my["max_neili"] * 3 / 2
	&& (int)ob->query_skill("shenzhao-jing", 1) > 100) {
		tell_object(ob, WHT"��Ǳ�ˡ����վ����ķ�������ض�����̩�����پ��Լ�����ԴԴ��ֹ�ˡ�\n"NOR);
		i = (int)ob->query_skill("shenzhao-jing", 1);
		if (ob->is_fighting()) i /= 2;
		my["neili"] += i + random(i * 2);
		if( my["neili"] > my["max_neili"] * 3 / 2) my["neili"] = my["max_neili"] * 3 / 2;
		update_flag++;
	}

	return update_flag;
}
