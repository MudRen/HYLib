
inherit NPC;

void create()
{
   set_name("�ο�",({ "you ke","you","ke"}) );
        set("gender", "Ů��" );
        set("age", 32);
   set("long", "����һ�����ϲ��۹���ο͡�\n");
       
   set("combat_exp", 50000);
   set("str", 10);
   set("per", 22);
   set("attitude", "peaceful");
   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

