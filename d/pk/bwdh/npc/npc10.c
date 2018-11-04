// modified by explorer, 3/9/97
inherit NPC;
void create()
{
        set_name("С���߹�", ({"hong qigong", "hong", "qigong"}));
        set("nickname", "��ָ��ؤ");
        set("gender", "����");
        set("age", 75);
        set("long", 
                "������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
        set("attitude", "friendly");
        set("str", 40);
        set("int", 24);
        set("con", 30);
        set("dex", 30);

	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 2400);
	set("max_jing", 2400);
	set("neili", 18000);
	set("max_neili", 18000);
	set("jiali", 300);
	
	set("combat_exp", 1000000);
	set("score", 200000);
	set("shen", 100000);
	 
	set_skill("force", 200);             // �����ڹ�
	set_skill("huntian-qigong", 300);    // ��������
	set_skill("unarmed", 200);           // ����ȭ��
	set_skill("xianglong-zhang", 300);   // ����ʮ����
	set_skill("dodge", 200);      	     // ��������
	set_skill("xiaoyaoyou", 250);        // ��ң��
	set_skill("parry", 200);             // �����м�
	set_skill("staff", 200);             // ��������
	set_skill("dagou-bang", 300);        // �򹷰���
	set_skill("begging", 200);           // �л�����
	set_skill("checking", 250);          // ����;˵
	set_skill("training", 250);         // Ԧ����
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );

        create_family("ؤ��", 17, "����");
        setup();

        carry_object(__DIR__"obj/yzb")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/badan");
}
