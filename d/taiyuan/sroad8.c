// /d/taiyuan/nroad1.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "�ร��");
	set("long", @LONG
�ร����̫ԭ������24������Χɽ֮��.ɽ�ƶ���,�ɰر�Ұ��
Ϊ̫ԭ�����羰֮һ��ȡ�ԡ����Ӷร��֮�⡣����ɽ��С��֮��
��������ɲ֮��Ȥ����ʼ��������Ԫ����(786��)����������á�
�����(����ׯ��)���������˷���㣬�¿���ǰ����ĩ���ڱ���
�����������(1368-1398)�ؽ������ֶ�����ޡ�Ψ��ǰɽ��ש��
�������δ�ԭ��������С�ݣ�����ĩ���˼��Ҹ�ɽ���鴦��

LONG
        );
set("outdoors", "/d/taiyuan");
set("valid_startroom", 1);
set("exits", ([
///                "southeast" : "/d/luoyang/huanghe_dukou2",
                "north":__DIR__"sroad7", 
	]));
       setup();
	replace_program(ROOM);
}
