inherit NPC;

void create()
{
	set_name("侍者", ({ "shi zhe", "shi", "zhe" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long", "一个下人。\n");
	set("shen_type", 1);
	set("combat_exp", 2000);
	set("str", 10);
	set("dex", 10);
	set("con", 10);
	set("int", 10);
	set("attitude", "peaceful");
	set_skill("dodge",20);
	set_skill("unarmed",20);
	set("chat_chance", 1);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 1);
}
