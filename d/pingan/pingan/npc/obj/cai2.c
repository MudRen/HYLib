// ������100�����II
// panzi.c ϴ�õ�����
// ����lywin 2000/6/1 ��ͯ��
#include <ansi.h>
inherit ITEM;
void create()
 {
 set_name( "���ָ����Ĳ�" , ({"cai"}));
set_weight(3);
if (clonep()) 
set_default_object(__FILE__);
else {                 set("unit", "��");
set("long", "һ�Ѹ��ָ����Ĳˡ�\n");
 }         setup();
 }
