// guanzho5.c
inherit NPC;
#include <ansi.h>
string ask_me();

void create()
{
	set_name("������", ({ "wu" }));
	set("long", 
		"������ò���ʨ�����ڣ�һ����֪����������ʿ��\n");
	set("gender", "����");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 22);
	
	set("max_qi", 200);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 5);
	set("combat_exp", 20000);
	set("score", 30000);

	set_skill("dodge", 40);
	set_skill("zhaixinggong", 30);
	set_skill("unarmed", 50);
	set_skill("chousui-zhang", 40);
	set_skill("parry", 60);

	map_skill("dodge", "zhaixinggong");
	map_skill("unarmed", "chousui-zhang");
  	map_skill("parry", "chousui-zhang");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object me, ob;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight"))
	{
		if( !ob->query_temp("warned") ) {
			command("say ���쿴Ϸ���ɣ��������㳢����ү�Ҷ��Ƶ�������");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			me->set_leader(ob);
			command("say ����������Ķ��ܣ�");
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

        remove_call_out("leave");
        call_out("leave",30);

}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "�������·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
