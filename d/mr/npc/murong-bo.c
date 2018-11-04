 // /u/beyond/mr/npc/murong-bo.c  Ľ�ݲ�
// this is made by beyond
// update 1997.6.23
inherit NPC;
inherit F_MASTER;
 

void create()
{
	set_name("Ľ�ݲ�",({"murong bo","murong","bo"}));
        set("title","����Ľ����ү��");
        set("nick","�Ա�֮�� ��ʩ����");
	set("long", 
              "���������ºų��Ա�֮��������֮��Ĺ���Ľ�ݲ���\n"
              "�����ϴ��Ų���һ����Ц�ݡ�\n");
        set("age", 57);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 60);
	set("int", 60);
	set("con", 60);
	set("dex", 60);
	
	set("max_qi", 26500);
	set("max_jing", 26500);
	set("neili", 28500);
	set("max_neili", 28500);
	set("jiali", 50);
	set("combat_exp", 9000000);
	set("score", 50000);                
        set_skill("xingyi-zhang",380);
        set_skill("strike",280);
        set_skill("finger",280);
        set_skill("dodge",280);
        set_skill("force", 280);
	set_skill("canhe-zhi", 380);
	set_skill("murong-jianfa",380);       
        set_skill("shenyuan-gong", 380);
	set_skill("yanling-shenfa", 380);
        set_skill("douzhuan-xingyi", 380);
	set_skill("parry", 320);
	set_skill("sword", 300);
	set_skill("literate", 300);
        set_skill("murong-daofa", 380);
        set_skill("blade",250);
         set_skill("hand", 380);
         set_skill("qxxy-shou", 380);
        set_skill("six-sword",380);       
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
        map_skill("hand", "qxxy-shou");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "douzhuan-xingyi");
	//if (random(3)==0)	map_skill("parry", "murong-jianfa");
	map_skill("sword", "six-sword");
                map_skill("strike", "xingyi-zhang");
       prepare_skill("finger", "canhe-zhi");
        prepare_skill("hand", "qxxy-shou");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                 (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.ci" :),
                (: perform_action, "finger.dianxue" :),
                 (: perform_action, "finger.jin" :),
                (: perform_action, "finger.canshang" :),
                 (: perform_action, "finger.lian" :),
                (: perform_action, "sword.lhj" :),
                (: perform_action, "sword.nbajian" :),
                (: perform_action, "sword.tx" :),
                (: perform_action, "sword.wbajian" :),
             		(: command("unwield sword") :),
		               (: command("wield sword") :),  
                (: perform_action, "dodge.yanling" :),                
                   (: perform_action, "strike.riyue" :),
                	(: perform_action, "strike.xingdian" :),
                (: perform_action, "hand.po" :),
                 (: perform_action, "hand.xy" :),
                (: perform_action, "hand.zhai" :),

        }));
                set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("����Ľ��",1,"����");

       	set("inquiry", 
                ([
                        "name" : "�Ҿ����Ա�֮������ʩ����Ĺ���Ľ�ݲ���\n",
                        "here" : "�����������µĲؾ�¥��\n",
                        "rumors" : "����Ľ�ݸ���������֮�д�������ͷ����ү�����������ѽ��\n",
                        
                ]));
       	setup();
	carry_object("/clone/weapon/gangjian")->wield();
    carry_object("/clone/misc/cloth")->wear();
	
}
void attempt_apprentice(object ob)
{
          object me  = this_player();
 
        string name, new_name;
	name = ob->query("name");
 
        if (present("jiaxin", me))
         {  destruct(present("jiaxin",me));

           command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "���Ҷ����ż�����Ϊ��" +
		"��������������Ҿ�������ɡ�");
 
           new_name = "Ľ��" + name[2..3];
	   ob->set("name", new_name);
           command("say �ӽ��Ժ���ͽ���" + new_name + "��ϣ�����ܰ�Ľ�ݹ�������");
           command("recruit " + ob->query("id"));
           command("chat ����һЦ��˭�� �Ա�֮�� ��ʩ���� ����������");
           command("chat* haha"); 
         }
        else
          command("say ��Ľ�ݲ����������ͽ!");
        return;
           
}
 

