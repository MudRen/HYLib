//changlang4.c ����
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short", HIY"���᳤��"NOR);
            set("long",@LONG
���᳤�ȶ̶����£������Ǿ�ɫ�����Ļ��ԣ�����ֲ���滨��ݸ�������
ϲ�������÷�������Χ�Ż���æ����ͣ�������ǹ���Ϣ��С�����Σ����о�
�µĵ񻨷��֣��������ӳ����˲��������������ϱ���������Ϣ�ҡ�
LONG
    );

            set("exits",([
                "north": __DIR__"sleep1",
                "south": __DIR__"sleep2",
                "east": __DIR__"lang1",
                "west": __DIR__"lang5",
            ]));
 
            setup();
}

int valid_leave(object me, string dir)
{
        if ((me->query("gender") == "Ů��") && dir == "north") 
           return notify_fail("Ů���Ӽ���ô�ܽ����˷����أ������Ժ���ô�����أ�\n");
        if ((me->query("gender") == "����") && dir == "south") 
           return notify_fail("��һ����������ô�ܽ�Ů���ӷ����أ�̫�����ˣ�\n");
        if ((me->query("gender") == "����") && (dir == "south" || dir == "north"))
	   return notify_fail("��λ����������û�еط�����������Ϣ��\n");
           return ::valid_leave(me, dir);
}
