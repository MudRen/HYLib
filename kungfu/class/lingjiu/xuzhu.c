// /NPC xuzhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "xu zhu", "xu", "zhu" }));
	set("long",
	    "����һ����ʮ�������������, Ũü����,\n"+
	    "���ı��ӱ�ƽ����, ��ò��Ϊ��ª. \n"+
	    "��һ���������µĳ���, ��ʹ�����Լ��־���.\n"+
	    "��������ɽͯ�ѵľ�������.\n");
	set("title", "���չ�������");
	set("gender", "����");
	set("age", 26);
	set("nickname", HIR "����" NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 50);
	set("int", 55);
	set("con", 50);
	set("dex", 50);

	set("qi", 15000);
	set("max_qi", 15000);
	set("jing", 12000);
	set("max_jing", 12000);
	set("neili", 38000);
	set("max_neili", 38000);
	set("jiali", 100);

	set("combat_exp", 8500000);
	set("score", 20000);
	set_skill("force", 150);
	set_skill("yangyanshu", 150);
	set_skill("unarmed", 180);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("hand",180);
	set_skill("strike", 180);
	set_skill("strike", 160);
	set_skill("sword", 160);
	set_skill("hand", 160);
	set_skill("qingyun-shou", 300);
	set_skill("panyang-zhang", 300);
	set_skill("liuyue-jian", 300);
	set_skill("zhemei-shou",300);
	set_skill("liuyang-zhang",300);
	set_skill("yueying-wubu",300);
	set_skill("bahuang-gong", 300);
        set_skill("tianyu-qijian",300);
	set_skill("wuzhan-mei", 200);
	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	
	create_family("���չ�",2, "����");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "strike.lianzhong" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "dodge.yueguangruying" :),                
        }));
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 1000);
        set_temp("apply/damage", 800);
        	setup();
	carry_object("/d/lingjiu/obj/changpao")->wear();

	add_money("silver",50);
}

void attempt_apprentice(object ob)
{
   if ((int)ob->query_skill("bahuang-gong", 1) < 50) 
           {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
		return;
	   }  
   if ((string)ob->query("gender")=="Ů��")
   {
		message_vision("����Ŀ��˼Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
       return;}
   else
      {
		message_vision("��������㿴�˰���,˵���������²������������ҵ������?��\n",ob);
       return;}
}
