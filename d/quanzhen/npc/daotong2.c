//Cracked by Kafei
// /kungfu/class/quanzhen/daotong.c
//   ��ͯ
// sdong 08/01/98

inherit NPC;

void create()
{
	set_name("��ͯ", ({ "daotong", "daotong" }));
	set("long",
		  "����һС��ʿ������Ц�ݣ��ܿɰ������ӡ�\n"
		);
	set("gender", "����");
	set("age", 12);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 20);
	set("int", 28);
	set("con", 28);
	set("dex", 20);

	set("max_qi", 200);
	set("max_jing", 100);
	set("max_jingli", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 1000);

	set_skill("force", 10);
	set_skill("xiantian-qigong", 10);
	set_skill("dodge", 10);
	set_skill("cuff", 10);
	set_skill("strike", 10);
	set_skill("parry", 10);
	set_skill("sword", 10);
	set_skill("literate", 10);
	set_skill("taoism", 10);

	create_family("ȫ���", 5, "����");

	set("class", "taoist");

	setup();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void serve_tea(object who)
{
        object ob;
        object room;

        if( !who || environment(who) != environment() ) return;

		  if( !objectp(room = environment()) ) return;

		  message_vision("С��ʿ�ó�һ�����ʵ�ˮ���ң������˱�����$N��\n", who);
		  ob = new("d/wudang/obj/xiangcha");
ob->set("value",0);
		  ob->move(this_player());
		  ob = new("d/wudang/obj/mitao");
ob->set("value",0);
		  ob->move(this_player());
		  message_vision("С��ʿ��$NһЦ����æ���к���������ȥ�ˡ�\n", who);

		  return;
}
