inherit NPC;

void create()
{
   set_name("С�ƹ�", ({ "dog" }) );
   set("race", "Ұ��");
   set("age", 3);
   set("long", "һֻë���޵�С����\n");
   
   set("str", 24);
   set("cor", 26);

   set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_chance", 6);
   set("chat_msg", ({
     (: call_other, this_object(), "random_move" :),
     "С�ƹ�����СȮ�����������С�\n",
     "С�ƹ�ҡ����β�ͣ�Χ����ת��Ȧ��\n",
     "С�ƹ�����Ȧ����ҧס�Լ���β�͡�\n",
     "С�ƹ��ú���ץ��ץ�Լ��Ķ��䡣\n", }) );
     
   set_temp("apply/attack", 10);
   set_temp("apply/armor", 3);

   setup();
}
int accept_object(object who, object ob)
{
   if( ob->id("bone") ) {
     set_leader(who);
     message("vision", name() + "���˵���������������\n", environment());
     return 1;
   }
}
