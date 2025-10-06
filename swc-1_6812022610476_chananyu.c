#include <stdio.h>
   
// ฟังก์ชั่นคำนวนเวลาทั้งหมด
float calculate_total_hours(int days, float hours_per_day) {
    return days * hours_per_day;
}

int main() {
    int day;
    float hours_per_day, total_hours, ot_rate, ot_income, final_income;
    char level;

    //รับข้อมูลจากคนใช้
    printf("ป้อนจำนวนวันทำ OT (1-10) : ");
    scanf(" %d", &days) ;

    printf("ป้อนจำนวนชั่วโมง OT ต่อวัน: ");
    scanf("%f", &hours_per_day)

      printf("กรอกระดับรายได้ (L, M, H): ");
    scanf(" %c", &level);  // มีช่องว่างก่อน %c เพื่อป้องกันการอ่าน \n

    // --- คำนวณชั่วโมงรวมทั้งหมด ---
    total_hours = calculate_total_hours(days, hours_per_day);

    // --- กำหนดอัตราค่า OT ต่อชั่วโมง ---
    if (level == 'L' || level == 'l')
        ot_rate = 75;
    else if (level == 'M' || level == 'm')
        ot_rate = 120;
    else if (level == 'H' || level == 'h')
        ot_rate = 180;
    else {
        printf("ระดับรายได้ไม่ถูกต้อง!\n");
        return 0;
    }

    // --- คำนวณรายได้ OT พื้นฐาน ---
    ot_income = total_hours * ot_rate;
    final_income = ot_income;

    // --- การหักภาษีตามเงื่อนไข ---
    if ((level == 'M' || level == 'm') && total_hours >= 220) {
        final_income -= ot_income * 0.05;
    } else if ((level == 'H' || level == 'h') && total_hours >= 240) {
        final_income -= ot_income * 0.15;
    }

    // --- เงื่อนไขพิเศษของระดับ H (ถ้า OT > 50 ชม.) ---
    if ((level == 'H' || level == 'h') && total_hours > 50) {
        final_income -= final_income * 0.05;
    }

    // --- แสดงผลลัพธ์ ---
    printf("\n------ สรุปผลการคำนวณ ------\n");
    printf("ชั่วโมง OT รวมทั้งหมด: %.2f ชั่วโมง\n", total_hours);
    printf("อัตราค่า OT ต่อชั่วโมง: %.2f บาท\n", ot_rate);
    printf("รายได้ OT ก่อนหัก: %.2f บาท\n", ot_income);
    printf("รายได้สุทธิหลังหักภาษี: %.2f บาท\n", final_income);

    return 0;
}
}
