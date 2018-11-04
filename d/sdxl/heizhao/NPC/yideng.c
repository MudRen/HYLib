// yideng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
int i,k,a,b,c,d,e,f,temp;
	set_name("һ�ƴ�ʦ", ({"yideng dashi", "dashi", "yideng"}));
	set("nickname", HIG "����һ��" NOR );
	set("gender", "����");
	set("age", 52);
	set("long", 
		"�����Ǻųơ��ϵۡ���һ�ƴ�ʦ�����������ˣ�����ѷλΪɮ��\n"
		"�����ֲ�ɮ�ۣ����������İ�ü���۽Ǵ�����������Ŀ���飬\n"
		"���봹�磬ü����������࣬��һ��Ӻ�ݸ߻�����ɫ��ȴ��һ\n"
		"����֪����ʦһ�����ƣ��������\n");
	set("attitude", "peaceful");
	set("class", "bonze");
	
d=60+random(60);
set("str",d);
set("dex",d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
	set_skill("force", 580);
        set("combat_exp", 8000000);
        set("shen_type", 1);

        set("max_neili", 200000);
        set("neili", 200000);
        set("jiali", 0);

	set("qi", 23000);
	set("max_qi", 23000);
	set("jing", 23000);
	set("max_jing", 23000);
	set("neili", 23500);
	set("max_neili", 223500);
	set("jiali", 100);
	
	set("combat_exp", 30000000);
	set("score", 0);
	set_temp("apply/attack", 150);
	set_temp("apply/armor", 510);
	set_temp("apply/damage", 515);
		set_temp("apply/defense",150);
	set_skill("force", 600);
	set_skill("dodge", 600);
	set_skill("parry", 600);
	set_skill("finger", 600);
	set_skill("strike", 600);
	set_skill("cuff", 600);
	set_skill("whip", 600);
	set_skill("sword", 600);
	set_skill("axe", 600);
	set_skill("tiannan-step", 600);
	set_skill("kurong-changong", 600);
	set_skill("duanjia-sword", 600);
	set_skill("duanyun-fu", 600);
	set_skill("wuluo-zhang", 600);
	set_skill("jinyu-quan", 600);
	set_skill("feifeng-whip", 600);
	set_skill("six-finger", 600);
	set_skill("sun-finger", 600);
	set_skill("buddhism", 600);
	set_skill("literate", 600);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	map_skill("axe", "duanyun-fu");
	map_skill("whip", "feifeng-whip");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	prepare_skill("finger","six-finger");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
//		(: perform_action, "sword.jingtian" :),	
		(: perform_action, "finger.yuqi" :),			
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	create_family("����μ�", 17, "����");
	setup();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("kurong-changong",1) < 500 )
	{
		command("say ��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɡ�");
		return;
	}
	if ((int)ob->query("shen") < 10000  ) {
		command("say �Ҵ�����������������壬����ذɣ�");
		return;
	}
	command("say �����ӷ��Ҿ����������ͽ�ܰɡ�");
	command("recruit " + ob->query("id"));
}
