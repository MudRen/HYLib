inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG     
�������嶾�̵Ĳ�Ժ���ط������������ң������ǽ�Ǳ߶�������
�õĲ��Ժ�������Ǹ��ϴ����׮��������ż��Ѵ�ͷ�������ǳ���
�Ĳ��ţ��ϱ���һ��դ����դ������������ܵĲ��֣�������դ����һ��
��δ���õ���׮��ƽʱ�����嶾�ڵ�����������
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                 "west" : "/d/wudujiao/chufang", 
]));        

        setup();
        replace_program(ROOM);
}
