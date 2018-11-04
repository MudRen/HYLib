// chen.c �½���

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_weiwang();
int ask_tuihui();
int ask_job();
int ask_fail();
string ask_me();

void create()
{
	set_name("С�½���", ({ "chen jinnan", "chen","jinnan" }));
	set("title", HIR "��ػ�"HIM"�ܶ���"NOR );
	set("nickname", HIC "Ӣ���޵�" NOR);
	set("long", 
		"\n����һ����ʿ����������������ɫ�Ͱ���\n"
		"������������������ػ��ܶ����½��ϣ�\n"
		"��˵ʮ�˰����գ�������ͨ��\n"
		"ż������߿��������پ���Ŀ����磬Ӣ�����ˡ�\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("literate", 200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("houquan", 300);
	set_skill("yunlong-xinfa", 300);
	set_skill("yunlong-shengong", 300);
	set_skill("wuhu-duanmendao", 300);
	set_skill("yunlong-jian", 320);
	set_skill("yunlong-shenfa", 300);
	set_skill("yunlong-bian", 300);
	set_skill("yunlong-shou", 300);
	set_skill("yunlong-zhua", 300);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	create_family("������",1, "��ɽ��ʦ");
	set("book_count", 1);
        set("inquiry", ([
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" :  "\nֻҪ������ػᣬ�������λ����ѧ���ա�\n",
                "���帴��" : "ȥ�ײĵ�ͻش�����ϸ���ưɣ�\n",
	]) );
	set("env/wimpy", 60);
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
                (: perform_action, "sword.xunlei" :),
                (: perform_action, "sword.xunlei" :),
                (: perform_action, "sword.xunlei" :),
                (: perform_action, "sword.duoming" :),
                (: perform_action, "sword.duoming" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "unarmed.pofuchenzhou" :),
	}) );
 	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/d/city2/obj/yaodai")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city2/obj/hlbian");
	carry_object("/d/city/obj/gangdao");
        carry_object(__DIR__"/obj/badan");
        carry_object(__DIR__"/obj/jinchuang");

}
