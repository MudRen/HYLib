//room: /d/tangmen/qiushi.c

inherit ROOM;
#include <ansi.h>
void create()
{
  set("short","����");
  set("long",
      "��������һƬ��ڣ�����Ÿոմ򿪵ĳ���һ������⣬�������澹Ȼ��һ��\n"
"�ˡ�����˱������������ţ����ܶ�������ͷ���棬����Ȼ���ó����Ȳ�����\n"
     );
   set("objects", ([
            "/d/tangmen/npc/xiao_qiushui":1
		 ]));	
  set("exits",([
      
          ]));

 setup();

}
void init()
{
	add_action("do_break", "break");
}
int do_break(string arg)
{
    int n;
	object me = this_player();

    if( !arg || arg!="bagua" )
	{
        write("���ŵĲ���������������ƻ��ģ�\n");
        return 1;
    }

    message_vision(
    "$N�ߵ�����ǰ�������������ȫ��������˫��бб������ԡ�\n", this_player());


    n = (int)me->query("neili");
    if (n >= 1500)
	{
        message_vision(
        HIR"$Nֻ��һ�����죡����������������\n"NOR, this_player());
        set("exits/up", "/d/tangmen/dating");
        this_player()->set("neili",n-1500);
        remove_call_out("close");
        call_out("close", 10, this_object());
    }
    else
	{
		message_vision(
		HIW"���ֻ��һ���ƺߣ�$N��������ķ����������ǰһ��....\n"NOR, this_player());
		this_player()->set("neili",0);
		this_player()->unconcious();
    }
return 1;
} 



void close(object room)
{
    message("vision","ֻ����һ��¸µ������������ַ���ת�����ָ���ԭ����\n", room);
    room->delete("exits/up");
}



