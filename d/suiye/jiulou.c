// "suiye"/jiulou
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "��¥");
	set("long", @LONG
��Բ����������������¥����˵�����˲�֪�����˲�����������ѧ
ʿ���ε��ˣ�������¥�Ļ�����޲����ڣ���ȻΪ�����ң�����һ�δ�
�麣�ڵļѻ����Ӵ�����¥��������¥�²��ü��ף��˿Ͷ��ǴҴҵ�
���ˣ������ӡ����ȡ��׾ƾ͸�·ȥ�ˡ� ¥����������
LONG
	);
set("exits", ([
		
                "south"  :__DIR__"dongdajie2",
	]));
	set("objects",([
	__DIR__"npc/xiaoer":1,
	]));
       setup();
	replace_program(ROOM);
}	
