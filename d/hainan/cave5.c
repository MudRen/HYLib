// Room: /d/hainan/cave5
inherit ROOM;

void create()
{
  set ("short", "С����");
  set ("long", @LONG
�ò����״�С����������,����ط����㿪���˵�.ͷ����ʯ������
��СС����Բ�촰,���������촰�������,��������,��һ��������״
��ʯͷ,�Ե÷���⻬.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"outcave",
  "southwest" : __DIR__"cave4",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "ʯͷ" : "���ʯͷ���ԱߵĶ�������ͬ,����ϸ���˿�,�ƺ������˾���Ħ��
��ԭ��,��֪���ܲ����ƿ�(push stone).
",
]));
  setup();
}
void init()
{
    add_action("do_push", "push");
    add_action("do_say","say");
}

int do_say(string sss)
{

object ob;
ob=this_player();
seteuid(geteuid(ob));
if((ob->query("master_id")=="zhongling")&&(ob->query("gender")=="����")&&(sss=="֥�鿪��"))
{
message_vision("$N˵��:֥�鿪��.\n",ob);
message_vision("�����ε�ʯͷӦ�����³�ȥ,$N���˽�ȥ. \n",ob);
ob->move(__DIR__"midao2.c");
  return 1;
 } 
}
int do_push(string sss)
 { object ob;
ob=this_player();
if ((sss=="stone")||(sss=="ʯͷ")) 
 message_vision("$N�������˰���,�����͵�ʯͷ��˿����. \n",ob);
  return 1;
 }
