// Room: /d/yandang/xiaolongq
inherit ROOM;
int last_time=-10000;

void create ()
{
  set ("short", "С����");
  set ("long", @LONG
С�����ٲ���һ��ɽ������������,��ͬһ������Ӿ�������,��
�»�ˮ��̶,̶���������,ˮ�о�ʯ���,ʯ����̦���,�����ܾ�û
�˵�����,���ܿչ�����,�˵ؽ���һ��.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shangty.c" : 1,
]));
  set("outdoors", "/d/yandang");
  set("exits", ([ /* sizeof() == 1 */
  "eastup" : __DIR__"wulonggu",
]));

  setup();
}
void init()
{
	add_action("do_search","search");
}
int do_search(string arg)
{
    object me,ob;
    int i;
    me=this_player();
    if (me->query("family/family_name")!="�㵴��")
{ if (!present("snake",this_object()))
clone_object(__DIR__"npc/mangshe")->move(environment(me));
return notify_fail("���ڲݴ��з�����ȥ,�������һ��ç��\n");}
 
    me->set_temp("search",me->query_temp("search")+1);

    if(me->query_temp("search")==3)
    {
      me->set_temp("search",0);

      i=time();
      if((i-last_time)>4200)
      { if ((int)me->query_skill("sword",1)>60){
      clone_object(__DIR__"obj/biyuzan")->move(environment(me));
	message_vision(
	"$N�ڲݴ����ҵ�һö��������\n", me);
      last_time=i;}
    else message_vision("$N�����ڻ���ѧ�ý����Ƚ���Ҫ,�����˷�ʱ����������������!\n",me);
      }
      else          
	message_vision("$N�ڲݴ���������ȥ,��㱻��ҧ��һ�ڣ�\n", me); 
    }
    else
      message_vision("$N�ڲݴ���������ȥ,ʲô��û�ҵ���\n", me);
    return 1; 
}
int valid_leave(object me, string dir)
{
  if(dir=="eastup") me->delete_temp("search");

  return ::valid_leave(me, dir);  
}
