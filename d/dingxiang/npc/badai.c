
inherit NPC;

void create()
{
   set_name("�����",({ "ba dai","ba" }) );
   set("gender", "Ů��" );
		
   set("age",22);
   set("long", "����ͻ���ɺ��ն���С���ӡ�\n");
       
   set("combat_exp",300000);
   set("per", 25);
   set("attitude", "peaceful");
   set_skill("dodge",130);
   set_skill("parry",130);
   set_skill("force",130);

   setup();
  
}

