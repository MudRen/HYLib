//li.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void greeting(object);
void init();
void create()
{
	set_name("���ͷ", ({ "li"}) );
	set("gender", "����" );
	set("age", 25);
	set("long", "���Ǹ��Ͱ����׵Ľ�ͷ��\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 400);
	set("max_jing", 500);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 1850000);
	set("score", 20000);

	set_skill("force", 180);
	set_skill("dodge", 190);
	set_skill("unarmed", 190);
	set_skill("parry", 180);
	set_skill("staff",180);
	
	set_skill("hamagong",170);
	set_skill("chanchu-bufa", 180);
	set_skill("lingshe-zhangfa", 180);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.saoluoye" :),
                (: command("unwield shengzhang") :),
                (: command("unwield shengzhang") :),
                (: command("wield shengzhang") :),
                (: command("wield shengzhang") :),
                (: perform_action, "strike.hama" :),                
                (: perform_action, "strike.hama" :),                
                (: perform_action, "hand.diaoshou" :),                
                (: perform_action, "hand.diaoshou" :),                
        }) );
	create_family("����ɽ��",2,"����");

	set("chat_chance", 2);
	set("chat_msg", ({
		"���ͷ˵��: ��ѧ�������ɳ���..\n",
		"���ͷ����С�����ǲ�η��࣬�ú�������\n",
		"���ͷ����ѧͽ��ͷ˵�������ģ�\n",
	}) );
	setup();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "����ɽ��")
	     {
	       message_vision("���ͷ����$N���ͷ��΢΢Ц��Ц��\n",ob);
	       return;
	      }
	if (!(string)ob->query("family/family_name"))
	     {
	       message_vision("���ͷ����$N΢Ц˵����������ʦ�İɣ����Ұɡ�\n",ob);
	       return;
	      }
	  message_vision("���ͷ��$N�µ�:С�һ�,��Ϲ��ʲô��?\n",ob);
}

void attempt_apprentice(object ob)
{
     command("say �ðɣ��������㡣\n");
     command("recruit "+ob->query("id"));
     if((int)ob->query("combat_exp")<10000)
       command("say ���ȵ�����������������ͯ�ӱȻ����аɡ�\n");
     return;
}

int accept_fight(object ob)
{
      if ((string)ob->query("family/family_name") == "����ɽ��")
	 {
	  if((int)ob->query("combat_exp")<1000)
	    return notify_fail("���ͷЦ������ľ���̫���ˣ�������������ͯ�ӱȻ����аɡ���\n");
	  }
    return 1;
}
