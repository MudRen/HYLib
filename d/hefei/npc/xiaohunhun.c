
inherit NPC;

void create()
{
   set_name("С���",({ "xiao hunhun","xiao","hunhun"}) );
   set("gender", "����" );
   set("age", 20);
   set("long", "����һ��С��죬�������ֵ��»���֪�����١�\n");       
   set("combat_exp",80000);
  
   set("chat_chance",30);
   set("chat_msg",({
     "С���������������ӹ�����������١������겻Ҳ�ǻ����û׼��Ҳ�������أ�\n",
     "С���Ц����û׼������Ҳ�ܳ�Ϊ���ָ����أ�\n",

   }));
   setup();
   
}

