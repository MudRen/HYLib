// mudage.c
//[xiaojl 1999/11/20 ����II]

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int sec, min, hrs, day, mon, age;
        string out_str;
    	write(HIY"  �� �Թ�̽�� �� \n"); 
if (!me->query("migong/lev1"))
    	write(HIR"  �Թ��� һ �� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ��� һ �� �� ��� ��     \n"); 
if (!me->query("migong/lev2"))
    	write(HIR"  �Թ��� �� �� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ��� �� �� �� ��� ��     \n"); 
if (!me->query("migong/lev3"))
    	write(HIR"  �Թ��� �� �� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ��� �� �� �� ��� ��     \n"); 
if (!me->query("migong/lev4" ))
    	write(HIR"  �Թ��� �� �� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ��� �� �� �� ��� ��     \n"); 
if (!me->query("migong/lev5"))
    	write(HIR"  �Թ��� �� �� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ��� �� �� �� ��� ��     \n"); 
if (!me->query("migong/lev6"))
    	write(HIR"  �Թ��� �� �� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ��� �� �� �� ��� ��     \n"); 
if (!me->query("migong/lev7"))
    	write(HIR"  �Թ��� �� �� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ��� �� �� �� ��� ��     \n"); 
if (!me->query("migong/lev8"))
    	write(HIR"  �Թ��� �� �� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ��� �� �� �� ��� ��     \n"); 
if (!me->query("migong/lev9"))
    	write(HIR"  �Թ��� �� �� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ��� �� �� �� ��� ��     \n"); 
if (!me->query("migong/lev10"))
    	write(HIR"  �Թ��� ʮ �� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ��� ʮ �� �� ��� ��     \n"); 
if (!me->query("migong/lev11"))
    	write(HIR"  �Թ���ʮһ�� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ���ʮһ�� �� ��� ��     \n"); 
if (!me->query("migong/lev12"))
    	write(HIR"  �Թ���ʮ���� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ���ʮ���� �� ��� ��     \n"); 
if (!me->query("migong/lev13"))
    	write(HIR"  �Թ���ʮ���� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ���ʮ���� �� ��� ��     \n"); 
if (!me->query("migong/lev14"))
    	write(HIR"  �Թ���ʮ�Ĳ� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ���ʮ�Ĳ� �� ��� ��     \n"); 
if (!me->query("migong/lev15"))
    	write(HIR"  �Թ���ʮ��� ��δ��ɡ�     \n"); 
else
    	write(HIC"  �Թ���ʮ��� �� ��� ��     \n"); 
if ((int)me->query("szj/failed")>3)        
    	write(HIR"  ����:���վ�  ��ʧ�ܡ�     \n"); 
if ((int)me->query("szj/passed"))        
    	write(HIC"  ����:���վ�  ���ɹ���     \n"); 
if ((int)me->query("jiuyin/shang-failed")>2)        
    	write(HIR"  ����:������  ��ʧ�ܡ�     \n"); 
if ((int)me->query("jiuyin/shang"))        
    	write(HIC"  ����:������  ���ɹ���     \n"); 
if ((int)me->query("jiuyin/xia-failed")>2)        
    	write(HIR"  ����:������  ��ʧ�ܡ�     \n"); 
if ((int)me->query("jiuyin/xia"))        
    	write(HIC"  ����:������  ���ɹ���     \n"); 
if ((int)me->query("jiuyin/emei"))        
    	write(HIC"  ����:�����ٳɡ��ɹ���     \n"); 
if ((int)me->query("jiuyin/full"))        
    	write(HIC"  ����:����ȫ�����ɹ���     \n"); 
if ((int)me->query("double_attack"))        
    	write(HIC"  ����:˫�ֻ������ɹ���     \n"); 
if ((int)me->query("jiuyin/gumu-failed")>2)        
    	write(HIR"  ����:������Ĺ��ʧ�ܡ�     \n"); 
if ((int)me->query("zhou/failed")>2)        
    	write(HIR"  ����:��  ��  ��ʧ�ܡ�     \n"); 
if ((int)me->query("zhou/fail")>2)        
    	write(HIR"  ����:��  ��  ��ʧ�ܡ�     \n"); 
if ((int)me->query("zhou/jieyi")>2)        
    	write(HIR"  ����:�������塺ʧ�ܡ�     \n"); 


        return 1;
}


int help(object me)
{
	write(WHT"\n���Թ�Ѱ������"NOR"\n");
	write(@HELP
    ������,��ҿ���ȥ�Թ�Ѱ��.�Թ���15��,������quest�Ͳ�������.
ÿ����Щ����,�ͱ���,��ҿ���kill ����,��openbox����򿪱���
�����еı����������,�����к���ͨ�Ķ���,Ҳ�������������,�书��
��, ������Ϊ���exp,pot,neili,�ڵ�5�����µ��Թ����ڱ��������
�ҵ�  ������  ������ ������ ���� ��Ե�� ��ò������������
�ҵ���,�������eat������,��exp,pot.�������ȫ��������,������
hebing���ϲ�����,���100000exp, 1000000pot,500 neili�����
����.(�򿪱���,Ҳ�������,�ж��Ŀ���)
���౦��˵��
������->ɽ��
������->����ʯ��
������->�Ҷ�
����->���Ҷ�
��Ե��->���Ҷ�
��ò��->�Ҷ�
��ȫ�����hebing��eat
������->ɽ��
������->����ʯ��
������->�Ҷ�
������->���Ҷ�
ˮ����->�Ҷ�
�ҵ������wear,�о޴�ս��Ч��
�����ȫ�Ļ�����
�������ˮ����ϱ�(wuzhuhebi)
�ϳ�ʥ����

    �ں��漸����boss�ػ�,���֮,�ɻ�exp,pot

    �����һ���л����ػ�,
    ���ǧ�����,�ɻ�ǧ������ף�������2000��
    �����ͨ����,�ɻ�����ף�������1000��

    �ڵ�6-12�㣬������һ���ط���������newup���򣬵��ﴫ˵�е�
ʥ�������������ս��12�ƽ�վʿ��ÿ���һ�ˣ��ɻ���20000�����
ȫ����ܣ��ɻ�ƽ�ʥ��һ��(������1200)�����������Ǳ�ܡ�
�������:12gong(�鿴����˼���)
 
 ע:1.������Σ�ռ���....
    2.��������ü�����teamȥ��....
    3.��������exp>100000exp
  4.ɱ�г�exp,pot�������
    lev1 exp < 200000
    lev2  300000
    lev3  700000
    lev4  1000000
    lev5  1500000
    lev6  2500000
    lev7  3000000
    lev8  3500000
    lev9  4500000
    lev10 6000000
    lev11 8000000
    lev12 9000000
    lev13 10000000
    lev14 12000000-15000000
    lev15 16000000-18000000
       
�������:openbox(������)mgmap(��ʾ������ͼ)
  ������2ת�󣬾���ﵽ20M,���������������ʦ���3תҪ��
3ת��,ֻ�������ԣ��͵��ߡ������Խ����Թ�16���Ժ��6�����磬
������ѧϰ���е��µļ��ܣ������������ϰ��ֵ��ˣ��ϰ��ֵ��ߣ�����
��������!!                        
HELP
	);
	return 1;
}