#include <ansi.h>
inherit ROOM;
void check_trigger();
void on_board();

void create()
{
        set("short", "Ϫ��");
        set("long", @LONG
��ӭ�����󺣷�������Ϫ�ڣ��������ԹŴ��������ұ���֮�أ�������
�����뺣���ó�ף�����ͣ���ŵļ��Ҵ󷫴���Ϧ���������£������Ե÷�
�������������м��������������������ˣ�Ҳ������ǰѯ��һ�¾��ܹʹ���
����
LONG);
        set("outdoors", "����");
        set("exits",([
        "west" : __DIR__"aywsi",
        "south" : __DIR__"dongqianhu",
        ]));
       
        setup();
}

