// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({"liang zhanglao", "liang", "zhanglao"}));
	set("title", "ؤ��Ŵ�����");
	set("nickname", "��������");
	set("gender", "����");
	set("age", 55);
	set("long", 
		"��������ؤ�������ã��书��ߵĳ��ϣ��������������Ѿá�\n"
		"ؤ���书������ǿ������������һ�����٣������������ϡ�\n");

	set("attitude", "peaceful");
        set("beggarlvl",9);
        set("class", "beggar");
//        set("no_get", "1");
	
	set("str", 28);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("qi", 3900);
	set("max_qi", 3900);
	set("jing", 3400);
	set("max_jing", 3400);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 120);
	
	set("combat_exp", 600000);
	
	set_skill("force", 190); 
	set_skill("huntian-qigong", 195); 
	set_skill("unarmed", 185); 
	set_skill("xianglong-zhang", 190); 
	set_skill("dodge", 193); 
	set_skill("xiaoyaoyou", 190); 
	set_skill("parry", 180); 
	set_skill("staff", 180); 
	set_skill("dagou-bang", 180); 
	set_skill("begging", 180); 
	set_skill("checking", 190);
	set_skill("training", 180);
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("staff", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");
		set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	create_family("ؤ��", 18, "�Ŵ�����");
	setup();
}

void init()
{
        object ob;
	mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) 
	{
		myfam = (mapping)ob->query("family");
		if (!myfam || myfam["family_name"] != "ؤ��")
		{
			remove_call_out("saying");
			call_out("saying",1,ob);
		}
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	message_vision("\n�����Ͽ���$N�����������һ�����㲻��ؤ����ӣ����ҹ���ȥ��\n\n", ob);
	call_out("kicking", 0, ob);	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;
    if (environment(ob)->query("short")=="������"){
	ob->move("/d/gaibang/inhole");
	message("vision","ֻ����ƹ����һ����" + ob->query("name") +
		"��С������˳�����\n", environment(ob), ob);
}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("str") < 25) {
		command("say ����ؤ�������һ���Ը���Ϊ����" + 
		RANK_D->query_respect(ob) + "����̫�����ƺ�����ѧؤ��Ĺ���");
		return;
	}

	command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
	"�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
