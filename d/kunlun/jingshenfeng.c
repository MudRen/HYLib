// jingshenfeng.c �����

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
set("short","�����"NOR);
	set("long",@long
�۶��򱱣�����һ�룬ֻ���Ű����Ѱ����£���ֱͦ���㣬�����и���
�ԣ������ض���������ݱ���߳�ʮ���ɣ�ֻ��������֮�������������ϸ
ϸ�������������ƺ����ﻥ��Ӧ�𣬼��عأ���ת������ֻ�����������
��һ���������ӱ��������ϥ�Ϸ���һ�Ž�β�٣����Ե��ࡣ��������ľ��
ͣ������ȸ����ݺ���ž飬ϲȵ���˸磬������಻֪�����ģ���������һ
��һ�𣬻������ͳ���
long);

set("objects",([
    "/kungfu/class/kunlun/hezudao.c" : 1,
    ])); 

set("exits", ([
"south" : __DIR__"sanshengao",
]));
	  set("outdoors", "kunlun");
	  setup();
replace_program(ROOM);
}
