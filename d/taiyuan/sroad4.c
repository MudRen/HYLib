// /d/taiyuan/nroad1.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "��Χɽ");
	set("long", @LONG
��Χɽ��̫ԭ��һ���羰ʤ�ء�����ɽ�ƶ������ɰر�Ұ������ɽ�����ţ�
������Ҷ��ɽ�� ����Χ��Ҷ����̫ԭ����ʤ��֮һ����ɽ��ǰ�Ķ���ɽ�嶥
�������жร�º��δ��߼������������ڲ����¹۱ڻ���վ����ǰ���ɸ��
̫ԭȫ����	
LONG
        );
set("outdoors", "taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "westdown":__DIR__"sroad3", 
                "northeast":__DIR__"sroad5", 
                
	]));
       setup();
	replace_program(ROOM);
}
