// miaofeng.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���ʹ", ({ "miaofeng shi", "miaofeng", "shi" }));
	set("long", "���˻���ӥ�ǣ�һ����֪���Ǹ����ˡ�\n");
	set("title",HIG "�����ܽ�"HIM"ʹ��"NOR);
	set("gender", "����");
	set("age", 30);
	set("shen_type",1);
	set("attitude", "friendly");
	set("class", "fighter");

	set("per", 28);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 12000);
	set("max_qi", 12000);
	set("jing", 11300);
	set("max_jing", 11300);
	set("neili", 13000);
	set("max_neili", 13000);
	set("jiali", 120);

	set("combat_exp", 1500000);
	set("score", 50000);
    
	set_skill("force", 150);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword",150);
	set_skill("jiuyang-shengong", 250);
	set_skill("qiankun-danuoyi", 250);
	set_skill("changquan",300);
	set_skill("shenghuo-ling",300);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "qiankun-danuoyi");
	map_skill("unarmed", "changquan");
	map_skill("sword","shenghuo-ling");
	map_skill("parry","shenghuo-ling");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",70);
}

void init()
{
        object me,ob;
        ::init();
        if (interactive(me = this_player()))
        {
                set_leader(me);
	        remove_call_out("kill_ob");
                call_out("kill_ob", 1, me);
        }
}

