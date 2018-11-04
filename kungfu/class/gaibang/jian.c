// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void consider();
string ask_me();
void create()
{
	set_name("����", ({"jian zhanglao", "jian", "zhanglao"}));
	set("title", "ؤ��Ŵ�����");
	set("nickname", "ִ������");
	set("gender", "����");
	set("age", 50);
set("beggarlvl",9);
	set("long", 
		"������ؤ���ִ�����ϣ�������ִ�Ʒ����Լ�������ȡ�\n"
		"������������𣬵�������˭���������־������顣\n");

	set("attitude", "peaceful");
        set("class", "beggar");
//        set("no_get", "1");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 3900);
	set("max_qi", 3900);
	set("jing", 3100);
	set("max_jing", 3100);
	set("neili", 5500);
	set("max_neili", 5500);
	set("jiali", 100);
	set("inquiry", ([
                "������" :     (: ask_me :)
	]));
	
	set("combat_exp", 800000);
	set("score", 20000);
		set_skill("fengmo-zhang",250);
	set_skill("liuhe-zhang",250);
	set_skill("strike",190);

	set_skill("force", 195); // �����ڹ�
	set_skill("huntian-qigong", 190); // ��������
	set_skill("unarmed", 190); // ����ȭ��
	set_skill("xianglong-zhang", 185); // ����ʮ����
	set_skill("dodge", 190); // ��������
	set_skill("xiaoyaoyou",195); // ��ң��
	set_skill("parry", 185); // �����м�
	set_skill("staff", 190); // ��������
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 18, "�Ŵ�����");
	setup();
}

init()
{
        object ob;
	mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
		myfam = (mapping)ob->query("family");
		if ((!myfam || myfam["family_name"] != "ؤ��") &&
			(!wizardp(ob))) {
			remove_call_out("saying");
			call_out("saying",2,ob);
		}
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment())
                return;

	message_vision("\n���Ͽ���$Nһ�ۣ������˵����������������˼�˵�Ҳ���"
	    "�������ؤ����ӣ�\n���ֲ�����ؤ��Ҵ����ܿ��԰ɣ���\n"
	    "˵������һ̧��$N˳��Ӧ��һ������ɵġ�ƨ�����ƽɳ����ʽ��"
	    "������ߴ\n\n", ob);
	remove_call_out("kicking");
	call_out("kicking",1,ob);
	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
    if (environment(ob)->query("short")=="����"){
	ob->move("/d/city/pomiao");
	 message("vision","ֻ�����ء���һ����������" +  ob->query("name") +
		"��С������˳�����ƨ������һ�������Ьӡ��\n", environment(ob), ob);
}
}

void attempt_apprentice(object ob)
{
	command("say �Ϸ���ͽ�ܣ�" + RANK_D->query_respect(ob) + "������ذɡ�");
}
string ask_me()
{
	mapping fam;
	object ob,me=this_player();
	string *sname;
	int i;

	if (!(fam = me->query("family")) || fam["family_name"] != "ؤ��")
		return RANK_D->query_respect(me) +
		"�뱾��������������֪�˻��Ӻ�̸��";

        ob = new(__DIR__"obj/qingzhu-ling");
        ob->move(me);
        message_vision("$N���һ�������\n",me);

        return "�ðɣ�ƾ���������������������ͬ�Ŵ�ʦ����ս��";

}
int accept_object(object ob, object obj)
{
	object me = this_object();

        mapping my_fam  = me->query("family");

       if (!my_fam || (my_fam["family_name"] != "ؤ��"))
                return notify_fail("���������������\n");

	if ( ob->query_temp("have_cloth") && present("po bu", ob) )
	{
		command("say ��Ȼ�������͵��μǰ�棬Ϊ�������");
message_vision("$N���Ʋ�����$n�����·��ϣ�ٲȻһ���¿ڴ���\n", me, ob);
		ob->delete_temp("have_cloth");
		ob->set("title",ob->query("newtitle"));
		if (ob->query("title") == "ؤ��һ������")
		{
		if (ob->query("beggarlvl") <= 1 )
			{
			ob->add("combat_exp",250);
			ob->set("beggarlvl",2);
                        }
			ob->set("beggarlvl",2);
		}
		if (ob->query("title") == "ؤ���������")
		{
		if (ob->query("beggarlvl") <= 2 )
			{
			ob->add("combat_exp",500);
			ob->set("beggarlvl",3);
                        }
			ob->set("beggarlvl",3);
		}
		if (ob->query("title") == "ؤ����������")
		{
		if (ob->query("beggarlvl") <= 3 )
			{
			ob->add("combat_exp",1000);
			ob->set("beggarlvl",4);
                        }
			ob->set("beggarlvl",4);
		}
		if (ob->query("title") == "ؤ���Ĵ�����")
		{
		if (ob->query("beggarlvl") <= 4 )
			{
			ob->add("combat_exp",1500);
			ob->set("beggarlvl",5);
                        }
			ob->set("beggarlvl",5);
		}
		if (ob->query("title") == "ؤ���������")
		{
		if (ob->query("beggarlvl") <= 5 )
			{
			ob->add("combat_exp",2000);
			ob->set("beggarlvl",6);
                        }
			ob->set("beggarlvl",6);
		}
		if (ob->query("title") == "ؤ����������")
		{
		if (ob->query("beggarlvl") <= 6 )
			{
			ob->add("combat_exp",3000);
			ob->set("beggarlvl",7);
                        }
			ob->set("beggarlvl",7);
		}
		if (ob->query("title") == "ؤ���ߴ�����")
		{
		if (ob->query("beggarlvl") <= 7 )
			{
			ob->add("combat_exp",4000);
			ob->set("beggarlvl",8);
                        }
			ob->set("beggarlvl",8);
		}
		if (ob->query("title") == "ؤ��˴�����")
		{
		if (ob->query("beggarlvl") <= 8 )
			{
			ob->add("combat_exp",5000);
			ob->set("beggarlvl",9);
                        }
			ob->set("beggarlvl",9);
		}
		if (ob->query("title") == "ؤ��Ŵ�����")
		{
		if (ob->query("beggarlvl") <= 9 )
			{
			ob->add("combat_exp",10000);
			ob->set("beggarlvl",9);
                        }
			ob->set("beggarlvl",9);
		}
ob->save();
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}
}
void destroying(object me, object obj)
{
	destruct(obj);
	return;
}
