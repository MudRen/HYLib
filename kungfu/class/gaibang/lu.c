// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("³�н�", ({"lu youjiao", "lu", "youjiao"}));
	set("title", "ؤ��Ŵ�����");
	set("nickname", "�ư���ͷ");
	set("gender", "����");
	set("age", 45);
	set("long", 
		"³�н���Ȼ�书�㲻�ö�����֣������ڽ�����ȴ����������\n"
		"��Ϊ����ؤ�����������壬���¹������䣬��ú��߹������ء�\n");
	set("attitude", "peaceful");
        set("beggarlvl",9);
        set("class", "beggar");
	set("str", 25);
	set("int", 12);
	set("con", 25);
	set("dex", 20);

	set("qi", 3900);
	set("max_qi", 3900);
	set("jing", 3100);
	set("max_jing", 3100);
	set("neili", 6200);
	set("max_neili", 6200);
	set("jiali", 100);
	
	set("combat_exp", 600000);
	set("score", 20000);
	
	set_skill("force", 190); // �����ڹ�
	set_skill("huntian-qigong", 190); // ��������
	set_skill("unarmed", 195); // ����ȭ��
	set_skill("xianglong-zhang", 190); // ����ʮ����
	set_skill("dodge", 190); // ��������
	set_skill("xiaoyaoyou", 190); // ��ң��
	set_skill("parry", 190); // �����м�
	set_skill("staff", 185); // ��������
	set_skill("begging", 160);
		set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 18, "�Ŵ�����");
	setup();
	carry_object(__DIR__"obj/jiaohuaji")->wield();
}

void attempt_apprentice(object ob)
{
	if ( (int)ob->query("int") >= 25 ) {
		command("say ����ؤ�������һ���Ը���Ϊ����" + 
		RANK_D->query_respect(ob) + "�ϻ۹��ˣ��ƺ�����ѧؤ��Ĺ���");
		return;
	}
	command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
	"�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
