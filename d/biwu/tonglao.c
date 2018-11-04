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

	set("str", 25);
	set("int", 35);
	set("con", 40);
	set("dex", 40);

	set("qi", 18000);
	set("max_qi", 18000);
	set("jing", 14000);
	set("max_jing", 14000);
	set("neili", 14000);
	set("max_neili", 14000);
	set("jiali", 100);

	set("combat_exp", 15500000);
	set("score", 200000);
	set_skill("yangyanshu", 200);
	set_skill("force", 200);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("hand",250);
	set_skill("strike", 250);
        set_skill("sword",150);

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
        set_temp("apply/attack", 400);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 350);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "powerup" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "sword.yushijufen" :),                
                (: perform_action, "dodge.yueguangruying" :),                
                (: perform_action, "dodge.yueguangruying" :),                
        }));
	create_family("���չ�",1, "��ɽ��ʦ");
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
   if ((int)ob->query_skill("bahuang-gong", 1) < 130) 
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
