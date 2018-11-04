// Jay 3/21/96

#include <ansi.h>

inherit NPC;

int do_look(string var);
int ask_me();

void create()
{
	set_name("��Ī��", ({ "li mochou", "li", "mochou" }));
	set("long", "�����ü�Ϊ��ò���������Ŀ�����˲���������\n");
	set("nickname", "��������");
	set("gender", "Ů��");
        set("pubmaster",1);
	set("rank_info/respect", "����");
	set("age", 27);
	set("attitude","heroism");
	set("str", 30);
	set("per", 28);
	set("dex", 35);
	set("con", 17);
	set("int", 25);
	set("shen_type", -1);

	set_skill("unarmed", 290);
	set_skill("force", 280);
	set_skill("dodge", 200);
	set_skill("whip",230);
	set_skill("chilian-shenzhang",300);
	set_skill("jueqing-bian",300);
	set_skill("taiji-shengong",150);
	map_skill("force", "taiji-shengong");
	map_skill("whip", "jueqing-bian");
	map_skill("strike", "chilian-shenzhang");
	map_skill("parry", "chilian-shenzhang");
	map_skill("force", "taiji-shengong");
        prepare_skill("strike","chilian-shenzhang");

	set("jiali",50);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "whip.sanwu" :),
        }) );

	set("combat_exp", 1895000);

	set("qi", 11500);
	set("jing", 11000);
	set("max_qi", 11500);
	set("max_jing", 11000);
	set("neili", 35000);
	set("max_neili", 35000);

	set("inquiry", ([
	    "name" : "վԶ�㣡",
	    "here" : "�Ҳ��Ǳ����ˣ���֪����",
	    "��" : "����������������˼֮�ࡢ���֮�⣿",
	    "½չԪ" : "�����Ǹ������С������ʲô��",
	    "�����" : (: ask_me :),
	    "С��Ů" : "�����ҵ�ʦ�á����������ʲô��",
	    "�ֳ�Ӣ" : "�����ҵ�ʦ�棬�������ʵ�����ʣ�С���������㡣",
       ]) );

	set("chat_chance", 10);
	set("chat_msg", ({
	    "��Ī���������裬�������񣬸�����������䣬���Ǻ��ֱ������������\n",
	    "��Ī�����������ϵر�˫�ɿͣ��ϳἸ�غ����\n",
	    "��Ī�����������Ȥ�����࣬���и��гն�Ů����\n",
	    "��Ī���������Ӧ�����������ƣ�ǧɽĺѩ��ֻӰ��˭ȥ����\n",
	    "��Ī����Ɐ�У��������ǰ�Թ�������������·����į������ġ���������ƽ������\n",
	    "��Ī���������л�Щ��ർ���ɽ��������ꡣ��\n",
	    "��Ī���������Ҳ�ʣ�δ���ˣ�ݺ�����Ӿ��������\n",
	    "��Ī�������ǧ����ţ�Ϊ����ɧ�ˣ����ʹ�����������𴦡���\n",
	}) );

	setup();
	carry_object("/d/quanzhou/obj/fuchen")->wield();
	carry_object("/d/wudang/obj/greenrobe")->wear();

}

void init()
{
	::init();
	add_action("do_look","look");
	add_action("do_look","hug");
	add_action("do_look","mo");
	add_action("do_look","18mo");
	add_action("do_look","kiss");

}

int ask_me()
{
	object me;

	me = this_player();
	if( environment(me)->query("no_fight") )
		return 0;

	   message("vision",
   HIY "��Ī����Цһ���������������ȥ������\n"
       "��Ī�����ɱ��" + me->name() +"\n"
   NOR, environment(), this_object() );
		   kill_ob(this_player());
   return 1;
}


int do_look(string target)
{
	object me;

	me = this_player();
	if( environment(me)->query("no_fight") )
		return 0;

	if (target=="li" || target=="li mochou" || target=="mochou" )
           if ((string)me->query("gender") != "Ů��") {
		   message("vision",
   HIY "��Ī���ŭ���ȵ��������������Щ����ĳ����ˣ�ȥ���ɣ�\n"
       "��Ī�����ɱ��" + me->name() +"\n"
   NOR, environment(), this_object() );
                   kill_ob(this_player());
           }
}

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timez"))      
		who->set_temp("learn_timez", 0);

	if( environment(who)->query("no_fight") )
		return 0;

	if( !ob->query("money_id") )
		return 0;		
           if ((string)who->query("gender") != "Ů��") {
		   message("vision",
   HIY "��Ī���ŭ���ȵ��������������Щ����ĳ����ˣ�ȥ���ɣ�\n"
       "��Ī�����ɱ��" + who->name() +"\n"
   NOR, environment(), this_object() );
                   kill_ob(who);
return 1;
           }

	if(who->query_skill("jueqing-bian",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("jueqing-bian",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("jueqing-bian",1)<100)
				i=ob->value() / 150;
			else
				i=ob->value() / 300;
		}
	}
	who->add_temp("learn_timez",i);

      message_vision("��Ī���$N˵������Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�\n",who);

	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timez") <= 0) return 0;
else         
ob->add_temp("learn_timez",-1);
return 1;
}
