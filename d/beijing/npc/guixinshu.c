// /beijing/npc/guixinshu.c
// Last modified by winder 2003.10.10

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("������", ({ "gui xinshu", "gui" }));
	set("nickname", HIR"��ȭ�޵�"NOR);
	set("long", 
"��ȭ�޵й������˻�ɽ���š�����Գ���������\n"
"�����ӣ��ڽ������ѳ������꣬���ǽ�����������\n"
"�������߶���\n");
	set("gender", "����");
	set("age", 78);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 50);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	
	set("qi", 15000);
	set("max_qi", 15000);
	set("jing", 14000);
	set("max_jing", 14000);
	set("neili", 13000);
	set("max_neili", 13000);
	set("jiali", 200);

	set("combat_exp", 2500000);
	set("score", 200000);

	set_skill("cuff", 220);
	set_skill("force", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("strike", 220);
	set_skill("zixia-shengong", 340);
	set_skill("poyu-quan", 320);
	set_skill("hunyuan-zhang", 320);
	set_skill("feiyan-huixiang",340);

	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");
	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");

	create_family("��ɽ��", 31, "����");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/d/beijing/obj/cloth")->wear();
}

