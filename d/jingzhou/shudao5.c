// Room: /d/chengdu/shudao5
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "ջ��" NOR );
        set("long", @LONG
ջ����ͨ�����Ĵ�����ԭ��Ψһ��·��Ϊ�����վ���ɽ����
��������·����֪�������˶����������������˶����ˣ�·��
�ؽ����޵ģ��ô�ľ׮���������ϣ���������ľ�壬���ܹ�һ��
���ˡ�ջ�����ʧ�ޣ�������ҡҡ�λεģ��ò�Σ�ա� 
LONG
        );
        set("exits", ([
  "east" :  __DIR__"shudao4",
  "northwest" : __DIR__"shudao6",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

