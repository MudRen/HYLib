inherit NPC;

void create()
{
	set_name("����", ({ "laner", "yahuan" }));
	set("gender", "Ů��");
	set("age", 16);
   
	set("combat_exp", 1000); 
	set("nickname","Ѿ��");
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);
    set("chat_chance", 7);
	set("chat_msg", ({
		"С������ȥ����������,�����Ͳ���������!\n",
       }));
	setup();
	add_money("silver",10);
	carry_object(__DIR__"obj/shiliuqun")->wear();
}
