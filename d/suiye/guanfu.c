// "suiye"/guanfu
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�ٸ�");
	set("long", @LONG
������Ҷ�Ĺٸ������������ֳִ����վ��һ�������š�����ʵ��
ûʲô��������Ϊ��������������Ҳ�����ٸ������ǹܲ���̫��Ĵ��
���ˣ�����Щ�����¾͵�Ԫ˧���ˡ�
LONG
	);
set("exits", ([
                "west"  : __DIR__"nandajie1",
                
	]));
       setup();
	replace_program(ROOM);
}	
