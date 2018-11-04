// qiao.c �Է�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�Է�", ({ "qiao fu", "qiao" }));
	set("title",  "������󽫾�" );
	set("long", 
"�����Ǵ������ԭ�󽫾���һ�ƴ�ʦ���Ĵ����֮һ��
��������һ���ɲ���������һ����ͷ����������ɫ��
׳����̬������������������Ǵ󽫾��а������硣��
�����ֲ����Ѷ�����ɽ�ּ��Բ񣬱ص����Ǹ�߳���
�Ƶ�ͳ����˧��\n");
	set("gender", "����");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);

		set_temp("apply/attack", 150);
	set_temp("apply/armor", 510);
	set_temp("apply/damage", 515);
		set_temp("apply/defense",150);
	set("max_qi", 15000);
	set("max_jing", 5000);
	set("neili", 15000);
	set("max_neili", 15000);
	set("jiali", 1000);
	set("combat_exp", 5000000);
	set("score", 10000);

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("parry", 200);
        set_skill("cuff", 200);
        set_skill("strike", 200);
        set_skill("sword", 200);
        set_skill("staff", 200);
        set_skill("finger", 200);
	set_skill("kurong-changong", 200);
        set_skill("tiannan-step", 250);
        set_skill("jinyu-quan", 250);
        set_skill("wuluo-zhang", 250);
        set_skill("duanjia-sword", 250);
        set_skill("sun-finger", 250);
	set_skill("literate", 200);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "sun-finger");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "sun-finger");
	map_skill("axe", "duanyun-fu");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jingtian" :),	
		(: perform_action, "finger.qiankun" :),			
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

        set("inquiry", ([
                "һ�ƴ�ʦ"   : "ʦ�������˼������档\n",
                "������"     : "������ʦ�����������䡣\n",
                "������"     : "������ʦ�����������ӡ�\n",
        ]) );

        set("chat_chance", 3);
        set("chat_msg", ({
"�����ӳ�����
    ���ǳؾ㻵��Ӣ�۰��ڣ����������ཻ��������˥����Ϊ�����ƼҲ�����Ұܣ���̬
�����Ʊ�ġ�����Ҳ����ز�٣�Ҳ����ز��\n",
"�����ӳ�����
    ��������ϣ�ƾ��ң����������������ɥ�����Բԣ�ˮãã����̨�������˽���ǧ��
תͷ������������Ҳ���ó�������Ҳ���ó�����\n",
"�����ӳ�����
    ���ǳؾ㻵��Ӣ�۰��ڣ����������ཻ��������˥����Ϊ�����ƼҲ�����Ұܣ���̬
    ��������ۣ�������ŭ��ɽ�ӱ�������·���������������顣�����غ����д�������
��䶼���������ˣ����տ࣡�������տ࣡��\n",
"�����ӳ�����
    ����ɽ����������మ���β��������۹��ƽ����һéի��Ұ����������˭���˷�˭
�ɰܣ�ª�ﵥư�����ա�ƶ�������ģ��־���ģ���\n",
"�����������������ڳ�������ô
    ��������ʱ������δ���Ӯ�������������䣬������������\n",
        }) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/axe")->wield();
	add_money("silver", 50);

	create_family("����μ�",25,"����");
}

