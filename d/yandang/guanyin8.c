// Room: /d/yandang/guanyin8
inherit ROOM;

void create ()
{
  set ("short", "�ھŲ�");
  set ("long", @LONG
���й������һ��ǧ�ֹ���,��̬����,ʹ�˶����ȱ�֮��,��ߵ�
ɽ������һ��ˮ��(chi),ϸϸ��ˮ���Ӷ����������,��������������
�Ķ���������.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  //"/obj/weapon/tulongdao.c" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "chi" : "ϴ��Ȫ������ʯ���е��䵽ϴ�ĳ���,��˵��ˮ��а��ħ,������Ч
������һ��.
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"guanyin7",
]));

	set("no_clean",1);
  setup();
}
void init()
{
    add_action("do_drink", "drink");
    add_action("do_drink", "he");
}
int do_drink(string sss)
{

object ob;
ob=this_player();
if ((sss!="chi")&&(sss!="shui")&&(sss!="water"))
  {
   return 0;
  }
if(ob->query("water")> ((int)ob->query("str")-10)*10+150 )
 {
  tell_object(ob,"������˻�Ҫ�Ȱ���\n");
  return 1;
 } 
else
 {  
 say(ob->query("name")+"ſ��ˮ�رߣ�һ�������˹���. \n");
 tell_object(ob,"��ſ��ˮ�رߣ�һ�������˹���. \n");
 ob->set("water",((int)ob->query("str")-10)*10+200);

  return 1;
 }

 }
