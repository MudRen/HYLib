// conglinggu.c �����(kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "�����");
		  set("long",@long
�����ǰͻȻΪ֮һ����ֻ��һ����һ��������Ͽ����ʯ�䣬��ɽ��ѩ
ˮк�䵽ǧ�����µ�ɽ����ȥ����������ܵķ�ĭ����һ�־��Ķ��ǵ��𺶡�
��������ɽҰ�ȵ�Ϫ���ߣ�ȴ�����˸��ָ����Ļ�����ľ�����췱������Ͽ��
�����ʵѹ��ɽ�����˼����������������ǵ���԰��
long);

		 set("exits",([
			"out" : __DIR__"shanlin"+(random(5)+1),
		 ]));

		 set("objects", ([
                        __DIR__"obj/huangqi.c" :  1,
                        __DIR__"obj/dongchongcao.c" : 2,
		 ]));

	setup();
	replace_program(ROOM);
}
