inherit NPC;

void create()
{
   set_name("��̽",({ "mi tan","mi","tan" }) );
        set("gender", "����" );
        set("age",30+random(10));
   set("long", "����һ���ٸ��ı�����̽��\n");       
   set("combat_exp",100000);
   set("str",30);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set_skill("dodge",80);
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set_temp("apply/armor",30);
   set("attitude", "peaceful");
   set("chat_chance",30);
   set("chat_msg",({
       "��̧̽��ͷ���˿���Χ��\n",
   }));
   set("kill_npc",1);
   setup();
 //  carry_object(__DIR__"obj/chouyi")->wear();
  
}

