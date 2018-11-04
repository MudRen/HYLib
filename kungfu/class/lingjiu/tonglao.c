// /NPC tonglao.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��ɽͯ��", ({ "tong lao", "tong", "lao" }));
	set("long",
	    "�����ǡ����չ����Ŀ�ɽ��ʦ.\n"+
	    "էһ���ƺ��Ǹ�ʮ�߰����Ů��,������ȴ����������.\n"+
	    "˫Ŀ���,��������,��������ʱ,����һ�����˵�����.\n");
	set("title", "���չ�����");
	set("gender", "Ů��");
	set("age", 96);
	set("nickname", HIR "Ψ�Ҷ���" NOR);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("str", 65);
	set("int", 65);
	set("con", 60);
	set("dex", 60);

	set("qi", 18000);
	set("max_qi", 18000);
	set("jing", 18000);
	set("max_jing", 18000);
	set("neili", 39000);
	set("max_neili", 39000);
	set("jiali", 100);

	set("combat_exp", 8500000);
	set("score", 200000);
	        set_skill("claw", 220);
        set_skill("throwing", 220);
        set_skill("goplaying", 100);
        set_skill("luteplaying", 100);
        
        set_skill("painting", 100);
        set_skill("medicine", 100);
        set_skill("construction", 100);
        set_skill("horticulture", 100);
        set_skill("dramaturgy", 100);

	set_skill("yangyanshu", 380);
	set_skill("force", 200);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("hand",350);
	set_skill("strike", 250);
        set_skill("sword",250);
	set_skill("sword",200);
	set_skill("strike", 260);
	set_skill("sword", 260);
	set_skill("hand", 360);
	set_skill("qingyun-shou", 380);
	set_skill("panyang-zhang", 380);
	set_skill("liuyue-jian", 380);

	set_skill("wuzhan-mei",380);
	set_skill("zhemei-shou",380);
	set_skill("liuyang-zhang",380);
        set_skill("tianyu-qijian",380);
	set_skill("yueying-wubu",380);
	set_skill("bahuang-gong", 380);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
        map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
        map_skill("sword","tianyu-qijian");

        prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                	(: exert_function, "shield" :),
                	(: exert_function, "dunzun" :),	
                (: perform_action, "sword.kuangwu" :),
                	(: perform_action, "sword.qing" :),
                		(: perform_action, "sword.ju" :),
               
                (: perform_action, "sword.san" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "strike.lianzhong" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "dodge.yueguangruying" :),                
        }));
	create_family("���չ�",1, "��ɽ��ʦ");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 1000);
        set_temp("apply/damage", 800);
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
}

void attempt_apprentice(object ob)
{
   
   if ((string)ob->query("gender")!="Ů��")
           {
 		command("say ��������!");
		return;
	   }
   if ((int)ob->query_skill("bahuang-gong", 1) < 160) 
           {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
		return;
	   }
   if (ob->query_con() < 30) 
      	   {
		command("say ���Ź�����Ϊ����,��ĸ����ƺ�����.");
		return;
	   }
   command("recruit " + ob->query("id"));
   if((string)ob->query("class") != "dancer")
     ob->set("class", "dancer");
   return;
}
