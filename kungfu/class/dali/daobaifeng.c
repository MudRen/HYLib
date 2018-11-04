// daobaifeng.c ���׷�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���׷�", ({ "dao baifeng", "dao" }));
	set("title",  "���������" );
	set("nickname",  CYN"����ɢ��"NOR );
	set("gender", "Ů��");
	set("long", "���Ǹ���ò������������ã��Ǹ�������Ů�ӣ�����Ӻ�����ʡ�
�����Ǵ�����ʵ۶�����������ԭ����ˡ�
�����ɷ�������մ���ǲݣ�һŭ֮���ܵ�������˼ҡ���������Լ��ʮ���ꡣ\n");
	set("age", 35);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 28);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 11800);
	set("max_jing", 1500);
	set("neili", 11500);
	set("max_neili", 11500);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 200000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("cuff", 200);
	set_skill("strike", 200);
	set_skill("whip", 200);
	set_skill("kurong-changong", 301);
	set_skill("duanjia-sword", 200);
	set_skill("tiannan-step", 200);
	set_skill("jinyu-quan", 200);
	set_skill("wuluo-zhang", 200);
	set_skill("feifeng-whip", 300);
	set_skill("literate", 60);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("whip", "feifeng-whip");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "feifeng-whip");
	map_skill("sword", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
	setup();
	carry_object("/d/dali/npc/obj/cynrobe")->wear();
	carry_object("/d/dali/obj/fuchen")->wield();
	add_money("silver", 10);

	create_family("����μ�",18,"����");
}

void attempt_apprentice(object ob)
{
	string oldtitle;
	oldtitle = ob->query("title");
	if ((int)ob->query_skill("kurong-changong",1) < 30 )
	{
		command("say ��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɡ�");
		return;
	}
	if ((string)ob->query("gender") != "Ů��")
	{
		command("say ��ֻ��Ů���ӡ�");
		return;
	}
	if ((int)ob->query("shen") < 10000  )
	{
		command("say �Ҵ�����������������壬����ذɣ�");
		return;
	}
	if (strsrch(oldtitle, "������������") >= 0) 
	{
		command("say �ܺã���Ȼ���������͵�����Ϊū������ʹ��");
		command("recruit " + ob->query("id"));
		ob ->set("title", oldtitle);
	}
	else
	{
		command("say ���Ǻ��ˣ���˴󵨣���ð�Ҹ������ͣ�");
		return;
	}
}
 
