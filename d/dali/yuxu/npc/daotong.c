// Modify By River 98/12
inherit NPC;

void create()
{
         set_name("С��ͯ", ({ "xiao daotong", "xiao","daotong" }));
	 set("gender", "Ů��");
	 set("age", 16);
         set("long", "����������ڵ�һ��С��ͯ��\n");
	
	 set("combat_exp", 10000);
         set("shen_type", 100);

	 set("attitude", "peaceful");
	
	 set_skill("unarmed", 40);
	 set_skill("dodge", 40);
	 set_temp("apply/attack", 10);
	 set_temp("apply/defense", 10);

	 setup();
	 carry_object(__DIR__"obj/greenrobe1")->wear();
}
