
inherit NPC;

void create()
{
   set_name("���ΰ����",({ "di zi","di","zi" }) );
   set("gender", "����" );
   set("age",18);

   set("long", "����һ�����ΰ�ĵ��ӡ�\n");
       
   set("combat_exp", 50000);
   
   set_skill("blade",50);
   set_skill("dodge",50);
   set_skill("parry",50);
   set_skill("force",50);
   
   
   setup();
   
   carry_object(__DIR__"obj/blade")->wield();

}

