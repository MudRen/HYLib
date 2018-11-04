// feng.c ������

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "feng qingyang", "feng", "qingyang" }));
	set("title", "��ɽ��ʮ�������ڳ���");
	set("long", 
"����ǵ������𽭺��Ļ�ɽ���޷�������������ۣ��������������ֽ��
����ݳ���ü���һֱ������һ�ɵ�����������ɫ����Ȼ�Ե���Ľ�������
֮��һֱ����������\n");
	set("gender", "����");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 19800);
	set("max_qi", 19800);
	set("jing", 8600);
	set("max_jing", 8600);
	set("neili", 24400);
	set("max_neili", 24400);
	set("jiali", 200);

	set("combat_exp", 3050000);
	set("score", 200000);

	set_skill("cuff", 200);
	set_skill("force", 180);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 320);
	set_skill("strike", 200);
	set_skill("zixia-shengong", 380);
	set_skill("poyu-quan", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",300);
        
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	create_family("��ɽ��", 12, "����");

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	int student_num;
	string temp;
	string line;

	if ((int)ob->query("betrayer") )
	{
		command("say ���ҿ�" + RANK_D->query_respect(ob) + "����ݹ����ɵ�ʦ����������Ҳ���ʺ�ѧ���¾Ž���");
		return;
	}
	if ((int)ob->query("mud_age") - (int)ob->query("feng_dietime") < 259200 )
	{
		command("say " + RANK_D->query_respect(ob) + "�����ԭ�����ҵ�ͽ���᣿");
		return;
	}

	temp = read_file("/data/FENG", 1, 1);
	student_num = atoi(temp);

	line = "������˵�����������ڹ���" + temp + "��ͽ�ܡ���\n";
	write(line);

//	if ( student_num == 10)
//	{
//		command("say �������ˣ����Ѿ�����ʮ��ͽ���ˡ�");
//		return;
//	}

	if ((string)ob->query("family/family_name") != "��ɽ��")
	{
		command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α������������أ�");
		return;
	}

	if (((int)ob->query_skill("sword",1) < 80) || ((int)ob->query_skill("huashan-sword",1) < 80))
	{
		command("say �ҿ�" + RANK_D->query_respect(ob) + "�Ļ�ɽ������ûѧ���Ұɡ�");
		return;
	}
	if (((int)ob->query_skill("force",1) < 80) || ((int)ob->query_skill("zixia-shengong",1) < 80))
	{
		command("say �ҿ�" + RANK_D->query_respect(ob) + "����ϼ�񹦻�ûѧ���Ұɡ�");
		return;
	}
	if (((int)ob->query_skill("dodge",1) < 80) || ((int)ob->query_skill("feiyan-huixiang",1) < 80))
	{
		command("say �ҿ�" + RANK_D->query_respect(ob) + "�ķ�����軹ûѧ���Ұɡ�");
		return;
	}
	if ( (int)ob->query_skill("literate",1) < 100)
	{
		command("say �ҿ�" + RANK_D->query_respect(ob) + "�Ķ���ʶ�ֻ�ûѧ���Ұɡ�");
		return;
	}

	if ((int)ob->query("shen") < 50000)
	{
		command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}

	if ((int)ob->query_int() < 20)
	{
		command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ�Ҷ��¾Ž���");
		return;
	}

	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
		ob->set("class", "swordsman");

	student_num++;
//	temp = itoa(student_num);
	if(student_num == 1)
		temp = "1";
	else if(student_num == 2)
		temp = "2";
	else if(student_num == 3)
		temp = "3";
	else if(student_num == 4)
		temp = "4";
	else if(student_num == 5)
		temp = "5";
	else if(student_num == 6)
		temp = "6";
	else if(student_num == 7)
		temp = "7";
	else if(student_num == 8)
		temp = "8";
	else if(student_num == 9)
		temp = "9";
	else if(student_num == 10)
		temp = "10";
	write_file("/data/FENG", temp, 1);
}
