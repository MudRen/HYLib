// Room: /d/hainan/cave3
inherit ROOM;

void create ()
{
  set ("short", "��ʶ�");
  set ("long", @LONG
��ǰ�ĵ���ͻȻ��������,��ֱ����,�����Լ���һ�����ɸߵ�ɽ��
��,�ұڴ�ֱ,ʯ�ڷ���,�Ӷ�����������ʯͷ,��״���ƴ��ë��,�ӱʶ�
������[33mȪˮ[37m����©��.
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "Ȫˮ" : "������ˮ��Դͷ,�ƺ�ֱ�Ӵ�ʯ����������,����ʮ���峺,����
�ȼ���(drink water)
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"cave1",
  "northdown" : __DIR__"cave4",
]));

  setup();
}
void init()
{
    add_action("do_drink", "drink");
}

int do_drink(string sss)
{

object ob;
ob=this_player();
if (sss!="water") 
   return 0;
if(ob->query("water")> ((int)ob->query("str")-10)*10+150 )
 {
  tell_object(ob,"�㱥�ǵĶ��Ӳ���������ô����\n");
  return 1;
 } 
else
 {  
 say(ob->query("name")+"�յ��ʶ�ǰ,���˼���ɽȪ. \n");
 tell_object(ob,"������ɽȪ,�����ú�������,������.... \n");
 ob->set("water",((int)ob->query("str")-10)*10+200);

  return 1;
 }

 }
