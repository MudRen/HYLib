// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "qiu popo", "qiu", "popo" }));
	set("long",
	    "����"+HIC"�����չ���"NOR+"����Ų��г��첿������.\n"+
	    "������ͯ�Ѷ���, ��������,������˪��\n");
        
        set("title", "��翷����չ�");
	set("nickname", HIC "���첿����" NOR);
	set("gender", "Ů��");
	set("age", 60);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("per", 21);
	set("class", "scholar");
	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 6300);
	set("max_qi", 6300);
	set("jing", 6500);
	set("max_jing", 6500);
	set("neili", 12000);
	set("max_neili", 12000);
	set("jiali", 80);
        set("level", 8);        
	set("combat_exp", 1700000);
	
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
        set_skill("sword",100);

	set_skill("zhemei-shou",180);
	set_skill("liuyang-zhang",180);
	set_skill("yueying-wubu",180);
        set_skill("xiaowuxiang", 170);
        set_skill("tianyu-qijian", 170);

	map_skill("force", "xiaowuxiang");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
   	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
	
        create_family("���չ�", 2, "����");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "strike.zhong" :),
		(: perform_action, "hand.duo" :),
		(: perform_action, "sword.san" :),
		(: command("unwield jian") :),
		(: command("wield jian") :),
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: command("unwield jian") :),
		(: command("wield jian") :),
            }) );
	set("master_ob",2);
	setup();
 	carry_object("/clone/weapon/changjian")->wield();
 	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        carry_object("/d/lingjiu/obj/jiudai");
        add_money("silver",25);
}

void init()
{
	object me, ob;
	mapping fam;

	::init();
	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&&  !environment(ob)->query("no_fight")
	&&  ((fam = ob->query("family")) && fam["family_name"] != "���չ�" ))
	{
		if (! ob->query_temp("warned")) 
		{
		        command("say ����������˲��ý������չ��������뿪��");
			ob->set_temp("warned", 1);
	        } else 
	        if (ob->query_temp("stay") < 5) 
                        ob->add_temp("stay", 1);
                else 
                {
			command("say �󵨿�ͽ�������ô����չ�������\n");
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}
}

void attempt_apprentice(object ob)
{

                
        if ((string)ob->query("gender")=="Ů��")
        {
		message_vision("�����Ŵ�Ŀ��˼Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
                command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
                return;
        } else
        {
		message_vision("�����ŵ����㿴�˰���,˵����������ֻ��Ů���ӣ���\n",ob);
                return;
        }
}
