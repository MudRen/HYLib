// little_monkey.c
#include <ansi.h>

inherit NPC;
int do_work(string arg);
void create()
{
	set_name("С��",({ "little monkey", "monkey"}) );
	set("gender", "����");
	set("race", "Ұ��");
	set("age", 2);
	set("long", "����һֻ��Ƥ��С���ӣ�����������ȴϲ��ģ��������\n"
	    "½����������̵����ޱ����������ƺ�����ץ��(zhua ��)\n");
	set("limbs", ({ "ͷ��", "����", "�Ȳ�", "β��",}) );
	set("verbs", ({ "bite" }) );
	set("shen", 0);
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
        set("attitude", "peaceful");

	set("no_get", "1");
	set("max_qi", 1600);
	set("qi", 1600);
	set("max_jing", 1600);
	set("jing", 1600);
	set("neili", 1600);
	set("max_neili", 1600);
	set("jiali", 10);
	set("combat_exp", 150000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 130);
	set("fight_times", 0);	
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance", 15);
	set("chat_msg", ({
		"С�����Сץ����ͷ��������������\n",
		"С����ץ׽ס�����ϵ�ʭ�ӣ��������ۣ�ʹ������һ��! \n",
        "С��������������ߴߴ����һ���ҽ�......!\n",
        "С���Ȼ���˹�����һ��������ǰצһ��ժ����Ĳ�ñ!\n",
        "С����һ��һ�����������������������������һ����!\n",
                (: random_move :),
	}));
	setup();
        
}
void init()
{
        add_action("do_work", "zhua");
}


int do_work(string arg)
{
        object me, ob, weapon;
int exp,pot;
        me=this_player();
 	ob=this_object();
 	if (!arg)
	return notify_fail("��Ҫץʲô����\n");

 	if (!id(arg))
	return notify_fail("��Ҫץʲô����\n");

        if( strsrch(file_name(environment(me)), "/d/huashan") == -1 )
                return notify_fail("���ﲻ�ǻ�ɽ�ˣ�ץʲôץ����\n");
        if (me->query("family/family_name")!="��ɽ��")
                return notify_fail("С��һ���㣬�ƺ��������ӿ��ˣ�\n");
	if( !living(ob) )
		return notify_fail(ob->name() + "�Ѿ����ȥ�ˡ�\n"); 
        if (!environment(me)->query("outdoors"))
                return notify_fail("���ڻ��⣬ץʲôץ��\n");
       if (!environment(me)->query("exits"))
                return notify_fail("����û�г���,ץʲôץ��\n");
        if (me->query("jing")< 30)
                return notify_fail("��ľ�������\n");

        if (me->is_busy())
                return notify_fail("����æ���ء�\n");

         tell_object(me, HIY"��͵͵���ܵ�С�����ߣ�һ����С��ץȥ��\n"NOR);
	ob->set("max_qi", 1600);
	ob->set("qi", 1600);
	ob->set("max_jing", 1600);
	ob->set("jing", 1600);
	ob->set("neili", 1600);
	ob->set("max_neili", 1600);

                        message_vision(HIM"һ����$N, ��Ȼ����������һ�������ܿ���......��\n"NOR, me);
                        message_vision(HIM"$N�۵���ͷ�Ǻ�......��\n"NOR, me);
                        me->add("jing",-10);
                        me->add_temp("hs_times",1);
                        me->start_busy(1);

                if (me->query_temp("hs_times")>(random(10)+8))
                {
                        message_vision(HIC"$Nһ��ץס��С�С��ߴߴ����һ���ҽ�,$Nһ���ְ�С�����.\n"NOR, me);
                        message_vision(HIC"$N�ľ����Ǳ��������!\n"NOR, me);
                        me->delete_temp("hs_times");
exp=random(50)+20;
pot=random(30)+18;
                        me->add("combat_exp", exp);
                        me->add("potential", pot);
	   tell_object(me,HIW"�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);
                }
                else  ob->random_move();
command("go north");
command("go north");
command("go north");
command("go east");
command("go east");
command("go north");
command("go northup");
command("go southup");
command("go eastup");
command("go westup");
command("go northdown");
command("go southdown");
command("go eastdown");
command("go westdown");
command("go northeast");
command("go northwest");
command("go southeast");
command("go southwest");
command("go south");
command("go west");
                return 1;
}

int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	me = this_object();

	if (is_fighting()) return 0;

	if (me->query("damaged"))
		return notify_fail("���С���Ѿ��������ˣ�\n");	

	if (random(me->query("fight_times")) >= 5) {
		me->set("damaged", 1);
		return notify_fail("���С���Ѿ��������ˣ�\n");	
	}

	if (me->query("last_fighter") == ob->query("id"))
		return notify_fail("���С���Ѿ�����������ˣ�\n");	

	me->set("last_fighter", ob->query("id"));
	me->add("fight_times", 1);

	remove_call_out("renewing");	
	call_out("renewing", 1000 + random(300), me);	


	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
	
	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("qi",        hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("combat_exp",hp_status["combat_exp"]);

	return 1;
}

void renewing(object me)
{
	me->delete("last_fighter");
}
