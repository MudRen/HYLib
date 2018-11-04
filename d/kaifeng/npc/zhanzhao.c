//Npc: /u/lots/npc/zhanzhao.c
// Date: LOTS 98/10/14

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("չ��", ({
		"zhan zhao",
		"zhao",
		"zhan",
	}));
	set("long",
		"����������������'��è',�ݴ������书�����Ħ��ʦ����޼�.\n"
		"�����ڱ��������˵İ�ȫ.\n"
	);


	set("nickname", "��ǰһƷ��������");
	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "officer");

	set("age", 30);
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);

	set("qi", 10000);
	set("max_qi", 10000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 150);
	set("combat_exp", 12000000);
	set("score", 1000000);

    set_skill("lamaism", 250);
        set_skill("literate", 80);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("blade", 380);
        set_skill("sword", 120);
        set_skill("dodge", 280);
        set_skill("longxiang", 380);
        set_skill("shenkong-xing", 280);
        set_skill("hand", 180);
        set_skill("dashou-yin", 380);
        set_skill("mingwang-jian", 320);
        set_skill("xue-dao", 380);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "dodge.tianmaxingkong" :),
              
		(: exert_function, "recover" :),
	}) );

       set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);


	set("inquiry", ([
	]));



	setup();

	carry_object(__DIR__"obj/goldblade")->wield();
	carry_object(__DIR__"obj/yayifu")->wear();
}

