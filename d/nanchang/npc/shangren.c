
inherit NPC;

void create()
{
   set_name("����",({ "shang ren","shang","ren" }) );
        set("gender", "����" );
        set("age", 42);
   set("long", "����һ�����ϴ��������ˣ����ϲ������Ρ�\n");
       
   set("combat_exp", 200000);
   set("str", 26);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("cuff",100);

   set("chat_chance",20);
   set("chat_msg",({
	   (:random_move:),
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
add_money("silver",2);
  
}

