// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;

void create()
{
        set_name("����ͷ��", ({ "kulou tougu" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�׹ǲҲ�,ÿ��ͷ�ǵĶ��϶������ָ��..\n");
        }
}


