

inherit NPC;
void create()
{
   set_name("������",({ "kang qiaoli","kang" }) );
        set("gender", "����" );
		
        set("age", 26);
   set("long", "������ͻ������ԭ�Ķ�Ŀ��\n");
       
   set("combat_exp",300000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",120);
   set_skill("dodge",120);
   set_skill("parry",120);
   set_skill("force",120);
   set_skill("blade",120);
   set_skill("literate",120);
   set_skill("cuff",120);

  
   

  
   set("gin",1000);
   set("max_jing",1000);
   set("kee",1000);
   set("max_qi",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("neili",1500);
   set("max_neili",1500);
   create_family("ͻ��",5,"��ʿ");
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}
