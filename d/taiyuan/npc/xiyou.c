inherit NPC;
void create()
{
   set_name("Ϸ��",({ "xi you","xi","you" }) );
   set("gender", "����" );
   set("age", 22);
   set("long", "����һ���ǳ�ϲ����Ϸ��Ϸ�ѡ�\n");
   set("combat_exp", 20000);
   
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set_temp("apply/armor",30);
   set("chat_chance",20);
   set("chat_msg",({
    "Ϸ�Ѹ����ȵ����ã����ĺã�����\n",
    "Ϸ���鲻�Խ�������̨�ϳ������������������������������ã��ã���\n",
    "Ϸ�ѳ���С����������С�����ٸ��������衫������\n",
    }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
