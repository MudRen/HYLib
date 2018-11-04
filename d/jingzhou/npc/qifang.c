// Room: /d/jingzhou/npc/qifang.c
// Date: 99/06/01 by Byt

#include <ansi.h>
inherit NPC;
int ask_yuan();
int ask_kong();
void create()
{
	set_name("�ݷ�", ({ "qi fang","qi","fang"}) );
	set("gender", "Ů��" );
	set("age", 24);
	set("long", "ֻ������һ���ںڶ�����������飬΢΢���̵ıǼ⣬ֻ����ɫ����Щ��\n");
	set("shen_type", 1);
	set("combat_exp", 5000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
        set("per", random(12)+20);
	set("attitude", "friendly");
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("score", 1000);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 12);
	set_temp("apply/damage", 11);
	set_temp("apply/armor", 7);
        set("inquiry", ([
            "����" : (: ask_yuan :),
            "���Ĳ�" : (: ask_kong :),
        ]) );	
         set("chat_chance", 10);
         set("chat_msg", ({
		"�ݷ���Ц���������˵���������Ĳˣ���㵽�Ķ������赽���Ҳ��š���\n",
		"�ݷ���Ц�Žе��������Ĳˣ��㻹����������\n",		
	}));        
	setup();
	carry_object("/clone/misc/cloth")->wear();
}



int ask_yuan()
{
	object me = this_player();
        command("consider");
        command("say ����Ϥ�ĵط�����������ɹ�ȳ��ϣ��һ���һ�����ӱ��Թ��书�ġ�\n");
        command("?");
        me->set_temp("yuan",1);
        return 1;
}

int ask_kong()
{
	object me = this_player();
	object ob;
if (this_object()->query("get") ) return 0;
	{
		message_vision(CYN"�ݷ�Ц�������Ѿ���������!\n"NOR,me);
		return 1;
	}

	if(me->query_temp("yuan")!=1)
	{
		message_vision(CYN"�ݷ�Ц�����������ҵ�Ů����\n"NOR,me);
		return 1;
	}
	else
	{
		message_vision(CYN"�ݷ���˼��һ������ó���һ����ݸ���$N��\n"NOR,me);	
		ob = new ("/d/jingzhou/obj/tangshixuan");
		ob->move(me);
this_object()->set("get",1);
		me->delete_temp("yuan");
		return 1;
	}
}	